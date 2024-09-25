#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>  // Added for wait()

// Global variable that will be shared between processes
int value = 5;

// Function that performs process management and returns the parent's value
int simulate_process_value_sharing() {
	pid_t pid;

    // Create a new process using fork
    pid = fork();

    if (pid == 0) {
        // This block is executed by the child process
        value += 15;  // Child modifies the value
        return 0;
    } else if (pid > 0) {
        // Parent process waits for the child to complete
        wait(NULL);
        return value;
    }
	return -1; // Return error if fork fails
}
	

int main() {
    printf("PARENT: value = %d\n", simulate_process_value_sharing());
	return 0;
}
