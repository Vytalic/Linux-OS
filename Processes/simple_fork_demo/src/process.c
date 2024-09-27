#include <sys/types.h> // required for pid_t
#include <sys/wait.h> // required for wait()
#include <stdio.h> // required for printf()
#include <unistd.h> // Required for fork()


int value = 5;

int main () {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        /* child process */
        value += 15;
        printf("CHILD: value = %d", value);
        return 0;
    }
    else if (pid > 0) {
        /* parent process */
        wait(NULL);
        printf("PARENT: value = %d", value);
        return 0;
    }
    return -1;
}