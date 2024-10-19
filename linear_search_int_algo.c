#include <stdio.h>

int main(void)
{
    // Initialize an array of integers to search through
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    
    // Variable to store the user input number
    int n;
    
    // Prompt the user to enter a number
    printf("Number: ");
    
    // Read the user input into the variable n
    scanf("%d", &n);

    // Iterate through each element in the numbers array
    for (int i = 0; i < 7; i++)
    {
        // Check if the current element matches the input number
        if (numbers[i] == n)
        {
            // If found, print the index of the matching element
            printf("Found inside: numbers[%i]\n", i);
            return 0; // Exit the program successfully
        }
    }
    
    // If no match was found, inform the user
    puts("Not found");
    return 1; // Exit the program with an error code
}
