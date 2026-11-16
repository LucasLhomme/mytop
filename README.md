# MyTop

> **Interactive system monitor and process viewer in C using NCurses.**

## Overview
Console-based diagnostic tool inspired by `top`:
- Real-time updates parsing `/proc` (`/proc/stat`, `/proc/meminfo`, `/proc/[pid]/stat`, `/proc/[pid]/cmdline`)
- Displays CPU load distribution, RAM/Swap usage, process counts, thread states, PID, user, memory, and command names

## Build & Usage
```bash
make
./my_top
```

## License
Open-source under MIT License.
