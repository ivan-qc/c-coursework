#include <stdio.h>

int main(void)
{
    // The smallest prime number
    int smallest_prime = 2;
    
    // Maximum value to check for prime numbers
    int max = 100;

    // Array to hold numbers from 2 to max
    int arr[max];

    // Initialize the array with consecutive integers starting from the smallest prime
    for (int i = 0; i < max; i++)
    {
        arr[i] = smallest_prime; // Set current index to the current smallest prime
        smallest_prime++; // Move to the next integer
    }

    // Sieve of Eratosthenes algorithm to find all prime numbers up to max
    for (int i = 0; i * i <= max - 2; i++)
    {
        // Check if the current number is still marked as prime
        if (arr[i] != 0)
        {
            // Mark all multiples of the prime number as non-prime (0)
            for (int j = 2 * arr[i]; j <= max; j += arr[i])
                arr[j - 2] = 0; // Set multiples to 0, adjusting index for the array
        }
    }

    /* Prints the prime numbers from the array */
    for (int i = 0; i < max - 1; i++)
    {
        // Print the number if it is still marked as prime
        if (arr[i] != 0)
            printf("[%d]\n", arr[i]);
    }
    
    return 0; // Return success
}
