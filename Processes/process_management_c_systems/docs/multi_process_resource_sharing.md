# Multi-Process Resource Sharing

## Introduction

In multi-process systems, resource management is crucial for ensuring data integrity and preventing race conditions. This document explains how processes interact with each other, focusing on how memory is shared between parent and child processes in C using the `fork()` system call.

## Process Isolation

When a process is forked, the child receives a copy of the parent’s memory space. However, these two processes operate independently after forking. Any changes made by the child do not affect the parent’s memory, as demonstrated in this project. The parent waits for the child to finish but does not observe the child’s modification to the shared variable.

## Use Case

In server applications, such as Apache or Nginx, each incoming request can trigger the creation of a child process to handle the request. Proper isolation between parent and child processes ensures that each child can safely modify its resources without interfering with the parent’s global state. This kind of process management is vital in avoiding resource contention or unexpected behavior in multi-threaded environments.

## Code Overview

The source code demonstrates how process memory isolation works. The parent creates a child process, which modifies a variable (`value`). The parent waits for the child to finish and prints the value, which remains unchanged.

### Key Takeaways

- Forking a process creates two independent processes with separate memory spaces.
- Memory isolation prevents changes in the child process from affecting the parent.
- This principle is critical in real-world systems where multiple processes need to run concurrently without interfering with each other.
