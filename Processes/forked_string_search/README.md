# Forked String Search

This program searches a text file named 'data.txt' for occurrences of the words 'easy' and 'polar'. Specifically, `fork()` is used two separate the work. The parent process searches for 'polar' while it's child process searches for 'easy'.

## Code Overview

- The 'data.txt' file is opened in read-only mode.
- The function `get_file_size()` is called to determine the file size.
- `malloc()` creates a character array called 'buffer' to hold the file contents.
- `fread()` is used to place the contents of the text file into the buffer.
- The file is closed using `fclose()` since its contents are now located in a buffer.
- `fork()` is called, and now there are two copies of the buffer - one for the child, one for the parent.
- The child process calls `count_easy()` to count the occurences of the word 'easy' in data.txt.
- The parent process calls `count_polar()` to count the occurences of the word 'polar' in data.txt.
- The parent calls `wait()`.
- Both processes free the allocated memory in the buffer using `free()`.
- A print statement outputs the occurences of each word.

## Key Behavior

- Determines size of data.txt
- Puts the contents of data.txt into a buffer
- `fork()` shares the work between child and parent
- Occurrences are printed to screen with `printf()`

## Output

An example output:
'easy' occurs 1 times.
'polar' occurs 15 times.

## Explanation

Since the contents of the text file are placed in a buffer before `fork()` is called, the child process will receive its own copy of this buffer. The child process also calls `printf()` before it exits so that the number of occurences of 'easy' is not lost. While both parent and child appear to be freeing the same buffer, they are actually freeing their own copy of the same buffer. Even though they share the same variable name (`buffer`), they reside in separate memory spaces due to the behavior of `fork()`. Each process handles its own memory independently.

## Running the Program

Include instructions for compiling and running the project. If applicable, also describe dependencies or specific setup steps:
```bash
gcc -pthread -o fss src/forked_string_search.c
./fss
```

## Additional Note

A DFA-like state machine (deterministic finite automata) was used to find specific words. It both reinforced my understanding of DFA and how it can relate to string-matching in a program.