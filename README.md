# Data Structures & Algorithms in C++

This repo contains implementations of core data structures and algorithms in C++.

## Getting started

1. Clone the project:

```bash
git clone https://github.com/pvictordev/dsa-cpp.git
```

2. Install the following packages:
   `sudo dnf install entr` , `sudo dnf install gcc-c++`

3. Run the script or use make run:

```bash
chmod +x scripts/build-and-run.sh
./scripts/build-and-run.sh
```

## How it works

- To simplify the compile-and-run workflow, I created a Bash script that continuously watches for file changes, recompiles the code, and reruns the application.
- When you start the program, you first select the option you want to run. On subsequent restarts, your previous selection is cached in the application state, so you don’t need to go through the same menu steps again after each rebuild.
