#include <stdio.h>

// Function prototype for the collatz function
int collatz(int number);

int main(void)
{
    int n; // Variable to hold the user input number
    
    // Display the title for the program
    puts(" *** The Collatz conjecture *** ");
    
    // Prompt the user for a number
    printf("Number: ");
    
    // Read the user's input and store it in variable n
    scanf("%d", &n);

    // Call the collatz function and print the result
    // The result indicates how many steps it takes to reach 1
    printf("Collatz: %d\n", collatz(n));

    return 0; // Indicate that the program ended successfully
}

// Function to calculate the number of steps in the Collatz sequence
int collatz(int number)
{
    // Base case: if the number is 1, return 0 steps
    if (number == 1)
        return 0;
    
    // If the number is even, divide it by 2 and count this step
    else if ((number % 2) == 0)
        return 1 + collatz(number / 2);
    
    // If the number is odd, compute 3 * number + 1 and count this step
    else
        return 1 + collatz(3 * number + 1);
}
