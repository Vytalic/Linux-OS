/* 
    Ben Clark
    CSci 451 - Operating Systems
    
    Description: This program takes a .txt file as input, searches for two words, and outputs two print statements.
    Input: .txt file
    Output: Number of occurrences of 'polar' and 'easy'.
*/


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


long get_file_size(FILE *file);
int count_easy(char* buffer);
int count_polar(char* buffer);


int main() {

    // Open the file
    FILE *file = fopen("data.txt", "r");

    // Check for errors
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Determine file size
    long fileSize = get_file_size(file);

    // Dynamically allocate memory and check for allocation error
    char *buffer = (char *)malloc((fileSize + 1) * sizeof(char));
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    // Place file contents into buffer
    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    buffer[bytesRead] = '\0';
    
    // File no longer needed
    fclose(file);

    // Fork process. Child will receive copy of memory, including the file in buffer.
    pid_t pid;
    pid = fork();

    if (pid == 0) { // Child process
        int count = count_easy(buffer);
        printf("'easy' occurs %d times.\n", count);

        // Free buffer for child process and exit
        free(buffer);
        _exit(0);
    } else if (pid > 0) { // Parent process
        int count = count_polar(buffer);
        printf("'polar' occurs %d times.\n", count);

        // Free buffer for parent process
        free(buffer);

        // Wait for child to finish
        wait(NULL);
    } else if (pid < 0) { // Fork failure, free allocated memory.
        perror("Fork failed!");
        free(buffer);
        return 1;
    }

    return 0;
}

long get_file_size(FILE *file) {
    // Set file pointer to end of file
    fseek(file, 0, SEEK_END);
    // Get file size
    long fileSize = ftell(file);
    // Reset pointer to beginning of file
    rewind(file);

    return fileSize;
}

int count_easy(char* buffer) {
    char c;
    int state = 0;
    int count = 0;

    // Iterate letter by letter to find "easy"
    for (int i = 0; buffer[i] != '\0'; i++) {
        c = tolower(buffer[i]);
        if (c == 'e' && state == 0) { // Looking for first 'e'
            state = 1;
        } else if (c == 'a' && state == 1) { // Found 'e', looking for 'a'
            state = 2;
        } else if (c == 's' && state == 2) { // Found 'ea', looking for 's'
            state = 3;
        } else if (c == 'y' && state == 3) { // Found 'eas', looking for 'y'
            count += 1;                     // Found 'easy'
            state = 0;                      // Look for 'easy' again
        } else state = 0; // String is not a match, go back to state 0.
    }
    return count;
}

int count_polar(char* buffer) {
    char c;
    int state = 0;
    int count = 0;

    // Iterate letter by letter to find "polar"
    for (int i = 0; buffer[i] != '\0'; i++) {
        c = tolower(buffer[i]);
        if (c == 'p' && state == 0) { // Looking for first 'p'
            state = 1;
        } else if (c == 'o' && state == 1) { // Found 'p', looking for 'o'
            state = 2;
        } else if (c == 'l' && state == 2) { // Found 'po', looking for 'l'
            state = 3;
        } else if (c == 'a' && state == 3) { // Found 'pol', looking for 'a'
            state = 4;
        } else if (c == 'r' && state == 4) { // Found 'pola', looking for 'r'
            count += 1;                      // Found 'polar'
            state = 0;                       // Look for 'polar' again
        } else state = 0; // String is not a match, go back to state 0.
    }
    return count;
}