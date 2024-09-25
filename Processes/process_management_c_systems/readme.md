# Process Management in C

This project demonstrates how to manage parent and child processes using `fork()` in C. It focuses on how processes handle shared resources and memory isolation, critical for multi-process systems in operating systems or server environments.

## Problem Statement

In multi-process systems, child processes often need to run concurrently with parent processes. Understanding how memory is shared (or not) between these processes is essential for system-level programming, where resource management and isolation are crucial.

This project simulates a scenario where a parent process creates a child process using the `fork()` system call. Both processes attempt to modify a shared variable, and this program shows how memory isolation works.

## Application in the Real World

This example mimics common situations in server environments, where each request may be handled by a child process, while the parent continues to accept new connections. Proper management of shared resources in such systems is critical to prevent data corruption or race conditions.

### Project Structure
- `src/process_value_sharing.c`: Demonstrates parent-child process creation and value modification.
- `docs/multi_process_resource_sharing.md`: A detailed explanation of how process forking works, its application, and best practices for managing resources in multi-process systems.
- `tests/process_management_tests.c`: Unit tests to verify the correct behavior of parent and child processes.

## Getting Started

### Prerequisites

- Linux or Unix-based OS
- C compiler (GCC or similar)

### Running the Program

To compile and run the program, use:

```bash
gcc src/process_value_sharing.c -o process_management
./process_management
