# Operation System Lab

A small collection of **Operating System lab** programs written in **C/C++** (process creation via `fork()`, CPU scheduling, deadlock algorithms, and page replacement).

This repo currently includes both:

- Source files: `Question*.c`, `Question*.cpp`
- Pre-built Linux executables: `Question1`, `Question2`, …, `Question12` (and `check`)

If you clone this on Linux/WSL, you can run the executables directly or rebuild from source.

## Requirements

- Linux (recommended) or WSL on Windows
- `gcc` for C programs
- `g++` for C++ programs

On Ubuntu/Debian:

```bash
sudo apt update
sudo apt install -y build-essential
```

## Programs included

### Process creation (C)

- **Question 1** (`Question1.c`): Basic `fork()` demo; prints child/parent PIDs.
- **Question 2** (`Question2.c`): `fork()` demo; parent prints `1..5`, child prints `6..10`.
- **Question 3** (`Question3.c`): Parent creates two children (two `fork()` calls).

### CPU scheduling (C++)

- **Question 4** (`Question4.cpp`): FCFS (First-Come, First-Served) scheduling; outputs TAT/WT + averages.
- **Question 5** (`Question5.cpp`): SJF (Shortest Job First) scheduling; prints a simple Gantt order + TAT/WT.
- **Question 6** (`Question6.cpp`): SRTF (Shortest Remaining Time First) preemptive scheduling; outputs TAT/WT.
- **Question 7** (`Question7.cpp`): Round Robin scheduling; outputs per-process TAT/WT (arrival times not used).
- **Question 8** (`Question8.cpp`): Priority scheduling (preemptive, smaller number = higher priority); prints completion times.

### Deadlock (C++)

- **Question 9** (`Question9.cpp`): Banker's algorithm (deadlock avoidance); prints a safe sequence when possible.
- **Question 9 (update)** (`Question9_update.cpp`): Deadlock detection variant; prints safe sequence or reports deadlock.
- **Question 10** (`Question10.cpp`): Deadlock detection using Allocation/Request/Available matrices; prints whether deadlock exists.

### Page replacement (C++)

- **Question 11** (`Question11.cpp`): FIFO page replacement; prints hits/faults and frame contents.
- **Question 12** (`Question12.cpp`): LRU page replacement; prints frame contents for each page reference.

### Misc

- `check.cpp`: Small C++ vector `find/insert` experiment used during development.

## Build & run

All commands below are meant to be executed from the repository root.

### Build a single program

**C files**:

```bash
gcc -Wall -Wextra -O2 Question1.c -o Question1
./Question1
```

**C++ files**:

```bash
g++ -std=c++17 -Wall -Wextra -O2 Question4.cpp -o Question4
./Question4
```

### Build everything (sources only)

```bash
# Build all C sources
for f in Question*.c; do
	out="${f%.c}"
	gcc -Wall -Wextra -O2 "$f" -o "$out"
done

# Build all C++ sources
for f in Question*.cpp; do
	out="${f%.cpp}"
	g++ -std=c++17 -Wall -Wextra -O2 "$f" -o "$out"
done
```

### Clean binaries

If you want to remove the compiled executables:

```bash
rm -f Question1 Question2 Question3 Question4 Question5 Question6 Question7 Question8 Question9 Question10 Question11 Question12 check
```

## Input notes (quick guide)

- Scheduling programs (`Question4`–`Question8`) prompt for process counts and times (arrival/burst/priority) and print computed results.
- Deadlock programs (`Question9`, `Question9_update`, `Question10`) expect matrices typed row-wise.
- Paging programs (`Question11`, `Question12`) ask for a page reference string and number of frames.

## Known quirks

- `Question8.cpp` currently prints completion times only (not TAT/WT).
- `Question9.cpp` prompts for “resources available”; the code reads **`p` integers** (process count) even though logically it should be **`r` integers** (resource count). If you run it as-is, enter the number of values the program is actually reading.

## VS Code

This repo includes `.vscode/` with tasks/launch configs that can help compile and run files inside VS Code.
