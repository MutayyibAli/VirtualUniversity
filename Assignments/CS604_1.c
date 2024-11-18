#include <sys/types.h> // Include header file for system data types (e.g., pid_t)
#include <stdio.h>     // Include header file for input/output functions (e.g., printf)
#include <unistd.h>    // Include header file for fork() and other process-related functions

// These lines were not present in the given code, so I added them to make the code compile and run
#include <sys/wait.h> // Include header file for wait() function
#include <stdlib.h>   // Include header file for standard library functions (e.g., exit)

int value = 5; // Declare and initialize a global integer variable 'value'

int main()
{
    pid_t pid;    // Declare a variable of type pid_t to store the process ID
    pid = fork(); // Create a new child process; fork() returns 0 for child, >0 for parent, -1 on error

    if (pid == 0)
    { // Check if this is the child process
        /* Child process */
        value += 15; // Increment the global variable 'value' by 15 in the child process
    }
    else if (pid > 0)
    { // Check if this is the parent process
        /* Parent process */
        wait(NULL);                        // Wait for the child process to finish
        printf("PARENT: value %d", value); // LINE A: Print the value of the global variable in the parent process
        exit(0);                           // Exit the parent process
    }
}
