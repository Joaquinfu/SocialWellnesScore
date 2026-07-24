#!/usr/bin/env python3
"""SWS results figure — plots the aggregator CSV as the symposium's
results slide: presence, proximity, gaze, and composite SWS vs time,
with the scripted scenario phases annotated as shaded bands.

Usage:
    python3 sws_plot.py <path/to/sws_YYYYMMDD_HHMMSS.csv>

Edit PHASES below to match the wall-clock transition times you noted
during the run (minutes from the start of the CSV).
"""
import sys
import csv
import matplotlib
matplotlib.use('Agg')  # no display needed; writes a PNG
import matplotlib.pyplot as plt

# ---- EDIT ME: (start_min, end_min, label, color) --------------------------
PHASES = [
    (0.0, 2.0, 'Engaged',              '#c8e6c9'),
    (2.0, 3.0, 'Present, disengaged',  '#fff9c4'),
    (3.0, 4.5, 'Absent',               '#ffcdd2'),
    (4.5, 5.5, 'Return, engaged',      '#c8e6c9'),
    (5.5, 6.5, 'Proximity sweep',      '#bbdefb'),
]
# ---------------------------------------------------------------------------

def main():
    if len(sys.argv) != 2:
        sys.exit('usage: python3 sws_plot.py <csv file>')
    path = sys.argv[1]

    t, presence, prox, gaze, sws = [], [], [], [], []
    with open(path) as f:
        for row in csv.DictReader(f):
            t.append(float(row['t_sec']))
            presence.append(float(row['presence']))
            prox.append(float(row['proximity']))
            gaze.append(float(row['gaze']))
            sws.append(float(row['sws']))

    t0 = t[0]
    tm = [(x - t0) / 60.0 for x in t]  # minutes from start

    fig, (ax1, ax2) = plt.subplots(
        2, 1, figsize=(11, 6.5), sharex=True,
        gridspec_kw={'height_ratios': [2, 1.2]})

    for start, end, label, color in PHASES:
        for ax in (ax1, ax2):
            ax.axvspan(start, end, color=color, alpha=0.55, zorder=0)
        ax1.text((start + end) / 2, 1.06, label, ha='center', va='bottom',
                 fontsize=8.5, transform=ax1.get_xaxis_transform())

    ax1.plot(tm, presence, label='Presence', lw=1.8)
    ax1.plot(tm, prox,     label='Proximity score', lw=1.8)
    ax1.plot(tm, gaze,     label='Gaze score', lw=1.8)
    ax1.set_ylabel('Component score (0-1)')
    ax1.set_ylim(-0.05, 1.12)
    ax1.legend(loc='center left', fontsize=9, framealpha=0.95)
    ax1.grid(alpha=0.25)

    ax2.plot(tm, sws, color='black', lw=2.0)
    ax2.set_ylabel('SWS (0-100)')
    ax2.set_xlabel('Time (minutes)')
    ax2.set_ylim(0, 105)
    ax2.grid(alpha=0.25)

    fig.suptitle('Social Wellness Score responding to scripted behavior '
                 '(live RGB-D pipeline)', fontsize=12)
    fig.tight_layout(rect=(0, 0, 1, 0.97))

    out = path.rsplit('.', 1)[0] + '_figure.png'
    fig.savefig(out, dpi=200)
    print(f'wrote {out}')


if __name__ == '__main__':
    main()
