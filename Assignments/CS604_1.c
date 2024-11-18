// Include header file for system data types (e.g., pid_t)
#include <sys/types.h>
// Include header file for input/output functions (e.g., printf)
#include <stdio.h>
// Include header file for fork() and other process-related functions
#include <unistd.h>

/* These lines were not present in the given code
so I added them to make the code compile and run */

// Include header file for wait() function
#include <sys/wait.h>
// Include header file for standard library functions (e.g., exit)
#include <stdlib.h>

// Declare and initialize a global integer variable 'value'
int value = 5;

int main()
{
    // Declare a variable of type pid_t to store the process ID
    pid_t pid;
    // Create a new child process;
    // fork() returns 0 for child, >0 for parent, -1 on error
    pid = fork();

    // Check if this is the child process or parent process
    if (pid == 0)
    {
        /* Child process */
        // Increment the global variable 'value' by 15 in the child process
        value += 15;
    }
    else if (pid > 0)
    {
        /* Parent process */
        // Wait for the child process to finish
        wait(NULL);
        // Print the value of the global variable in the parent process
        printf("PARENT: value %d ", value);
        // Exit the parent process
        exit(0);
    }
}
