#include <stdio.h>  // Required for printf()
#include <unistd.h> // Required for fork()
#include <sys/types.h> // Required for getpid(), getppid()

int main() {
    int i;
    pid_t pid;

    for (i = 0; i < 4; i++) {
        pid = fork();
        
        // Add some delay to better visualize the process creation
        usleep(10000);
        if (pid == 0) { // Child process
            // Indentation to show generations (child process gets more indented)
            printf("%*sChild Process: PID = %d, Parent PID = %d\n", i * 4, "", getpid(), getppid());
        } else { // Parent process
            printf("%*sParent Process: PID = %d, Forking a Child\n", i * 4, "", getpid());
        }
    }
    return 0;
}
