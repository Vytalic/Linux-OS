#include <stdio.h>
#include <unistd.h>

int main() {
    
    /* Fork a child process */
    // One process creates a child
    fork();
    printf("Process ID: %d, ParentID: %d\n", getpid(), getppid());

    /* Fork a child process */
    // Two processes each create a child
    fork();
    printf("Process ID: %d, ParentID: %d\n", getpid(), getppid());

    /* Fork a child process */
    // Four processes each create a child
    fork();
    printf("Process ID: %d, ParentID: %d\n", getpid(), getppid());

    return 0;
}
