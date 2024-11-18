#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Added for thread compatibility

// Thread function for T1: Prints array and its squares
void *calculate_squares(void *arg)
{
    int *array = (int *)arg;
    printf("In First Thread:\n");
    printf("Printing the actual array:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("\nPrinting the squares of numbers in the array:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d^2 = %d\n", array[i], array[i] * array[i]);
    }
    return NULL;
}

// Thread function for T2: Reverses the string
void *reverse_string(void *arg)
{
    char *str = (char *)arg;
    int len = strlen(str);
    char reversed[len + 1];
    for (int i = 0; i < len; i++)
    {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    printf("\nIn Second Thread:\n");
    printf("Printing the Reversed string: ");
    printf("%s\n", reversed);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    int array[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    char str[100];

    // Get input string from user and handle errors
    printf("Enter string to pass T2: ");
    if (scanf("%99s", str) != 1)
    {
        fprintf(stderr, "Error reading input string.\n");
        return 1;
    }
    printf("\n");
    
    // Create Thread T1 for calculating squares and printing them
    if (pthread_create(&thread1, NULL, calculate_squares, array) != 0)
    {
        fprintf(stderr, "Error creating thread 1.\n");
        return 1;
    }

    // Create Thread T2 for reversing the string
    if (pthread_create(&thread2, NULL, reverse_string, str) != 0)
    {
        fprintf(stderr, "Error creating thread 2.\n");
        return 1;
    }

    // Wait for both threads to complete and handle errors
    if (pthread_join(thread1, NULL) != 0)
    {
        fprintf(stderr, "Error joining thread 1.\n");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0)
    {
        fprintf(stderr, "Error joining thread 2.\n");
        return 1;
    }

    printf("\nExiting the main function\n");
    return 0;
}
