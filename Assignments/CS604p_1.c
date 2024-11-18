#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Added for thread compatibility

#define ARRAY_SIZE 10

// Thread function for T1: Prints array and its squares
void *thread1_func(void *arg)
{
    int *array = (int *)arg;
    printf("In First Thread\n");
    printf("Printing the actual contents of array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("\nPrinting the squares of numbers in the array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d^2 = %d\n", array[i], array[i] * array[i]);
    }
    return NULL;
}

// Thread function for T2: Reverses the string
void *thread2_func(void *arg)
{
    char *str = (char *)arg;
    int len = strlen(str);
    char reversed[len + 1];
    for (int i = 0; i < len; i++)
    {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    printf("\nIn second Thread, Printing the Reverse String...\n");
    printf("%s\n", reversed);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    int array[ARRAY_SIZE] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    char str[100];

    // Input string for T2
    printf("Enter string to pass T2: ");
    if (scanf("%99s", str) != 1)
    {
        fprintf(stderr, "Error reading input string.\n");
        return 1;
    }

    // Create Thread T1
    if (pthread_create(&thread1, NULL, thread1_func, array) != 0)
    {
        fprintf(stderr, "Error creating thread 1.\n");
        return 1;
    }

    // Create Thread T2
    if (pthread_create(&thread2, NULL, thread2_func, str) != 0)
    {
        fprintf(stderr, "Error creating thread 2.\n");
        return 1;
    }

    // Wait for both threads to complete
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
