"""
BNF 抖动诊断可视化工具

用法:
    python visualize_bnf.py <debug_dir>

会读取 debug_dir/debug_bnf_raw.bin, debug_bnf_batch.bin, debug_bnf_lab.bin
生成 4 张图:
    1. BNF 时间-能量热图 (batch 区域,每行一个 tick 的 batch BNF)
    2. BNF 帧间欧氏距离曲线 (突变点 = 抖动)
    3. 各 tick 的 batch RMS vs BNF 能量
    4. LabFlat 帧间一致性

关键诊断指标:
    - 帧间 L2 距离突变:说明 BNF 在该点不连续,会引起口型跳动
    - batch RMS 跌到 0 之后 BNF 突然变化:确认末尾抖动
    - LabFlat 上的窗口对齐错误:确认 winStart 计算问题
"""

import numpy as np
import matplotlib.pyplot as plt
import struct
import sys
import os

BNF_DIM = 256
AUDIO_WIN = 20


def read_bnf_raw(path):
    """读取 debug_bnf_raw.bin: 每个 tick 头 [int32 tick_idx, int32 num_frames] + float32 rms + (NumFrames × 256) float32"""
    ticks = []
    with open(path, 'rb') as f:
        while True:
            hdr = f.read(8)
            if len(hdr) < 8:
                break
            tick_idx, num_frames = struct.unpack('ii', hdr)
            rms = struct.unpack('f', f.read(4))[0]
            data = np.frombuffer(f.read(num_frames * BNF_DIM * 4),
                                 dtype=np.float32).reshape(num_frames, BNF_DIM)
            ticks.append({
                'tick': tick_idx,
                'num_frames': num_frames,
                'rms': rms,
                'bnf': data,
            })
    print(f"[raw] {len(ticks)} ticks, frames/tick = {[t['num_frames'] for t in ticks[:5]]}...")
    return ticks


def read_bnf_batch(path):
    """读取 debug_bnf_batch.bin: 每个 tick 头 [int32 tick_idx, int32 B] + (B × 256) float32"""
    ticks = []
    with open(path, 'rb') as f:
        while True:
            hdr = f.read(8)
            if len(hdr) < 8:
                break
            tick_idx, B = struct.unpack('ii', hdr)
            data = np.frombuffer(f.read(B * BNF_DIM * 4),
                                 dtype=np.float32).reshape(B, BNF_DIM)
            ticks.append({'tick': tick_idx, 'B': B, 'bnf': data})
    print(f"[batch] {len(ticks)} ticks, B={ticks[0]['B'] if ticks else 0}")
    return ticks


def read_bnf_lab(path):
    """读取 debug_bnf_lab.bin: 每个 tick 头 [int32 tick_idx, int32 B] + (B × 256 × 20) float32"""
    ticks = []
    with open(path, 'rb') as f:
        while True:
            hdr = f.read(8)
            if len(hdr) < 8:
                break
            tick_idx, B = struct.unpack('ii', hdr)
            data = np.frombuffer(f.read(B * BNF_DIM * AUDIO_WIN * 4),
                                 dtype=np.float32).reshape(B, BNF_DIM, AUDIO_WIN)
            ticks.append({'tick': tick_idx, 'B': B, 'lab': data})
    print(f"[lab] {len(ticks)} ticks")
    return ticks


def plot_bnf_timeline(batch_ticks, raw_ticks, out_path):
    """图1: batch 区 BNF 拼成一条时间线,看抖动位置"""
    # 拼接所有 tick 的 batch BNF: (total_frames, 256)
    all_bnf = np.concatenate([t['bnf'] for t in batch_ticks], axis=0)
    tick_boundaries = np.cumsum([t['B'] for t in batch_ticks])

    # RMS 序列 (从 raw_ticks 取)
    rms_per_tick = [t['rms'] for t in raw_ticks]
    bnf_norm_per_frame = np.linalg.norm(all_bnf, axis=1)

    fig, axes = plt.subplots(3, 1, figsize=(14, 10), sharex=False)

    # (1) BNF 热图
    ax = axes[0]
    im = ax.imshow(all_bnf.T, aspect='auto', origin='lower',
                   cmap='RdBu_r', vmin=-2, vmax=2, interpolation='nearest')
    ax.set_title("BNF heatmap (batch region only, time → right, 256 dims ↑)")
    ax.set_ylabel("BNF dim")
    ax.set_xlabel("frame (across all ticks)")
    plt.colorbar(im, ax=ax)

    # (2) BNF L2 norm 曲线 (能量) + RMS 对照
    ax = axes[1]
    ax.plot(bnf_norm_per_frame, label='BNF L2 norm', color='C0', linewidth=0.8)
    ax.set_ylabel("BNF L2 norm", color='C0')
    ax.set_xlabel("frame")
    ax.tick_params(axis='y', labelcolor='C0')
    ax.set_title("BNF energy vs batch audio RMS  (highlight where they diverge!)")

    ax2 = ax.twinx()
    # 把 rms_per_tick 拉成 per-frame (每个 tick 重复 B 次)
    rms_per_frame = []
    for r, t in zip(rms_per_tick, batch_ticks):
        rms_per_frame.extend([r] * t['B'])
    rms_per_frame = np.array(rms_per_frame[:len(bnf_norm_per_frame)])
    ax2.plot(rms_per_frame, label='audio RMS', color='C3', linewidth=0.8, alpha=0.7)
    ax2.set_ylabel("audio RMS", color='C3')
    ax2.tick_params(axis='y', labelcolor='C3')
    ax2.axhline(1e-3, color='C3', linestyle=':', alpha=0.5, label='RMS=1e-3')

    # (3) 帧间 L2 距离 = "突变指标"
    ax = axes[2]
    diff = np.linalg.norm(np.diff(all_bnf, axis=0), axis=1)
    ax.plot(diff, color='C2', linewidth=0.6)
    ax.set_title("BNF frame-to-frame L2 distance  (spikes = JITTER!)")
    ax.set_xlabel("frame")
    ax.set_ylabel("||BNF[i] - BNF[i-1]||₂")

    # 标记 tick 边界
    for ax in axes:
        for tb in tick_boundaries:
            ax.axvline(tb, color='gray', linestyle=':', alpha=0.3, linewidth=0.5)

    plt.tight_layout()
    plt.savefig(out_path, dpi=100)
    plt.close()
    print(f"  saved: {out_path}")


def plot_raw_vs_batch(raw_ticks, batch_ticks, out_path):
    """图2: 每个 tick 的整段 BNF 和 batch BNF 对比, 看 future_ctx 影响"""
    n = min(len(raw_ticks), len(batch_ticks))
    if n == 0:
        return

    # 在每个 tick 内部画 BNF L2 norm 曲线, 标出 ctx/batch/future 边界
    # 选最后 6 个 tick 看尾部
    show_ticks = list(range(max(0, n - 6), n))

    fig, axes = plt.subplots(len(show_ticks), 1, figsize=(14, 2 * len(show_ticks)),
                              sharex=True)
    if len(show_ticks) == 1:
        axes = [axes]

    for ax, i in zip(axes, show_ticks):
        bnf_raw = raw_ticks[i]['bnf']             # (num_frames, 256)
        n_frames = bnf_raw.shape[0]
        norm = np.linalg.norm(bnf_raw, axis=1)
        ax.plot(norm, color='C0', linewidth=1.0, label='BNF L2 norm')

        # ctx (0-20), batch (20-20+B), future (20+B+)
        B = batch_ticks[i]['B']
        ax.axvspan(0, 20, alpha=0.1, color='gray', label='past_ctx')
        ax.axvspan(20, 20 + B, alpha=0.15, color='C2', label='batch')
        ax.axvspan(20 + B, n_frames, alpha=0.1, color='C3', label='future_ctx')

        ax.set_title(f"Tick {raw_ticks[i]['tick']} (RMS={raw_ticks[i]['rms']:.4f})  "
                     f"frames={n_frames}")
        ax.set_ylabel("BNF norm")
        if ax == axes[0]:
            ax.legend(loc='upper right', fontsize=8)

    plt.tight_layout()
    plt.savefig(out_path, dpi=100)
    plt.close()
    print(f"  saved: {out_path}")


def plot_lab_consistency(lab_ticks, out_path):
    """图3: LabFlat 帧间一致性. LabFlat[fi] 和 LabFlat[fi-1] 应该高度相关 (20帧窗口只滑动1帧)"""
    if not lab_ticks:
        return

    # 把所有 LabFlat 拍扁: list of (256*20,) 向量
    all_lab = []
    for t in lab_ticks:
        for fi in range(t['B']):
            all_lab.append(t['lab'][fi].flatten())
    all_lab = np.array(all_lab)  # (total_frames, 256*20)

    # 相邻 LabFlat 的余弦相似度
    norms = np.linalg.norm(all_lab, axis=1, keepdims=True)
    norms[norms < 1e-8] = 1e-8
    normalized = all_lab / norms
    cos_sim = np.sum(normalized[1:] * normalized[:-1], axis=1)

    # L2 距离
    l2 = np.linalg.norm(np.diff(all_lab, axis=0), axis=1)

    fig, axes = plt.subplots(2, 1, figsize=(14, 6))

    axes[0].plot(cos_sim, color='C0', linewidth=0.6)
    axes[0].set_title("LabFlat frame-to-frame cosine similarity  (drops = jitter)")
    axes[0].set_ylabel("cos sim")
    axes[0].axhline(0.98, color='r', linestyle=':', alpha=0.5)
    axes[0].set_ylim(0.5, 1.01)

    axes[1].plot(l2, color='C2', linewidth=0.6)
    axes[1].set_title("LabFlat frame-to-frame L2 distance")
    axes[1].set_ylabel("L2")
    axes[1].set_xlabel("frame")

    plt.tight_layout()
    plt.savefig(out_path, dpi=100)
    plt.close()
    print(f"  saved: {out_path}")


def detect_jitter_spikes(batch_ticks, raw_ticks, threshold_stds=4.0):
    """自动检测抖动点并打印到 stdout"""
    all_bnf = np.concatenate([t['bnf'] for t in batch_ticks], axis=0)
    diff = np.linalg.norm(np.diff(all_bnf, axis=0), axis=1)
    mu, sigma = np.median(diff), np.std(diff)
    threshold = mu + threshold_stds * sigma

    spikes = np.where(diff > threshold)[0]
    print(f"\n=== JITTER DETECTION ===")
    print(f"Median frame-diff: {mu:.4f}, std: {sigma:.4f}")
    print(f"Threshold: {threshold:.4f}  ({threshold_stds} σ)")
    print(f"Spikes found: {len(spikes)}")

    # 把每个 spike 映射回 (tick_idx, fi)
    tick_boundaries = np.cumsum([t['B'] for t in batch_ticks])
    for sp in spikes[:30]:
        # sp 是 "frame i+1 - frame i" 的位置, 实际抖动出现在第 sp+1 帧
        tick_i = np.searchsorted(tick_boundaries, sp + 1, side='right')
        if tick_i < len(batch_ticks):
            local_fi = sp + 1 - (tick_boundaries[tick_i - 1] if tick_i > 0 else 0)
            tick_label = batch_ticks[tick_i]['tick']
            rms = raw_ticks[tick_i]['rms'] if tick_i < len(raw_ticks) else -1
            print(f"  frame {sp+1}: diff={diff[sp]:.4f}, tick={tick_label}, "
                  f"fi_in_tick={local_fi}, rms={rms:.4f}")


def main():
    if len(sys.argv) < 2:
        debug_dir = "."
    else:
        debug_dir = sys.argv[1]

    raw_path   = os.path.join(debug_dir, "debug_bnf_raw.bin")
    batch_path = os.path.join(debug_dir, "debug_bnf_batch.bin")
    lab_path   = os.path.join(debug_dir, "debug_bnf_lab.bin")

    raw_ticks   = read_bnf_raw(raw_path)   if os.path.exists(raw_path)   else []
    batch_ticks = read_bnf_batch(batch_path) if os.path.exists(batch_path) else []
    lab_ticks   = read_bnf_lab(lab_path)   if os.path.exists(lab_path)   else []

    if batch_ticks and raw_ticks:
        plot_bnf_timeline(batch_ticks, raw_ticks,
                          os.path.join(debug_dir, "bnf_timeline.png"))
        plot_raw_vs_batch(raw_ticks, batch_ticks,
                          os.path.join(debug_dir, "bnf_raw_vs_batch.png"))
        detect_jitter_spikes(batch_ticks, raw_ticks)

    if lab_ticks:
        plot_lab_consistency(lab_ticks,
                             os.path.join(debug_dir, "bnf_lab_consistency.png"))

    print("\nDone.")


if __name__ == "__main__":
    main()