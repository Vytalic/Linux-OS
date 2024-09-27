# Multiple Forks

This program explores what happens when multiple `fork()` system calls are made in sequence. The goal is to figure out how many processes are running and how many print statements are executed after the last `fork()` call.

## Code Overview

This program uses three consecutive `fork()` system calls, and after each `fork()`, it prints the process ID (`getpid()`) and the parent process ID (`getppid()`). Each `fork()` creates a new process, and all processes (parent and child) continue executing the subsequent code.

## Key Behavior

Each time a `fork()` is called, the number of processes doubles. Given 3 `fork()` calls, the number of processes after the final `fork()` is:
- 2^3 = 8 processes.

## Output

The expected output consists of 14 print statements showing the process ID and parent ID for each process. This happens because:
- After the first `fork()`, there are 2 processes, each of which prints once.
- After the second `fork()`, there are 4 processes, each of which prints once.
- After the third `fork()`, therea re 8 processes, each of which prints once.

## Explanantion

Each `fork()` creates a new child process, and both the parent and child continue executing the program from the point immediately after the `fork()` call. At the end of the program, there are 8 processes running, but each process prints multiple times because it continues executing after each `fork()`.

## Running the Program

To compile and run the program:
```bash
gcc -o multiple_forks multiple_forks.c
./multiple_forks
```

## Conclusion

This program illustrates how multiple `fork()` calls create a rapidly increasing number of processes. After three `fork()` calls, there are 8 process, and the total number of print statements is 14 due to the exponential growth of processes.