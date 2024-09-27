# Simple Fork Demo 

This project demonstrates a fundamental concept in process management: how parent and child processes in Unix-like systems have separate memory spaces after a `fork()`. In this example, the child process modifies a global variable, but the parent process does not see the change.

## Code Overview

The program creates a child process using the `fork()` system call. This is what happens:
- Before forking, both the parent and child processes share the same memory space.
- After the `fork()`, the parent and child processes have their own separate memory spaces, each with a copy of the variable value.

## Key Behavior:

- The child process increments the global variable value by 15.
- the parent process waits for the child ot finish using `wait(NULL)`.
- Even though the child modifies value, the parent still sees the original value of 5 when it prints the variable.

## Output:

The expected output when this program is ran:
- CHILD: value = 20
- PARENT: value = 5

## Explanation:

The `fork()` system call creates a new child process, and both the parent and child processes receive copies of the variable value. However, any changes mad eby the child to its copy of value are not visible to the parent process because they each have their own memory space after the `fork()`.
This illustrates the principle that variables are not shared between parent and child processes after a `fork()`, even though they start with the same values.

## Running the Program

To compile and run the program, use:
```bash
gcc src/process.c -o process
./process
```

## Conclusion

This simple demonstration highlights one of the key concepts in process management: how memory is handled after a `fork()`. The child process gets a copy of the parent's memory, but changes made by one process do not affect the other.