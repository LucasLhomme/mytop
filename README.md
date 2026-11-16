# 📊 MyTop — Interactive System & Process Monitor in C with NCurses

[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Library: NCurses](https://img.shields.io/badge/Library-NCurses-yellow.svg)](https://invisible-island.net/ncurses/)
[![Module: B-PSU-100](https://img.shields.io/badge/Epitech-B--PSU--100-blue.svg)](https://www.epitech.eu/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Epitech: Tek1](https://img.shields.io/badge/Epitech-Tek1-005696.svg)](https://www.epitech.eu/)

> **MyTop is an interactive terminal task monitor inspired by `top(1)`**, tracking Linux system activity and process statistics in real time.

---

## 🔍 System Telemetry via `/proc`

Rather than calling external commands, `my_top` parses Linux kernel virtual files directly:
- `/proc/stat`: CPU load across user, system, idle, and iowait states.
- `/proc/meminfo`: RAM and Swap usage (Total, Free, Available, Buffers/Cached).
- `/proc/loadavg`: 1-minute, 5-minute, and 15-minute system load averages.
- `/proc/[PID]/stat` & `/proc/[PID]/status`: Per-process state, memory RSS, PID, user, priority, and runtime.

---

## 🛠️ Build & Usage

```bash
make
./my_top
```

---

## 📜 License

Licensed under the **MIT License with attribution** to Lucas Lhomme (Crabe).
