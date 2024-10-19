#include <stdio.h>

// Function prototype for show_bits
void show_bits(int n);

int main(void)
{
    int i; // Variable to hold user input
    printf("Number: "); // Prompt user for a number
    scanf("%d", &i); // Read an integer from user input
    
    show_bits(i); // Call function to display the binary representation of the number
    return 0; // Return success status
}

// Function to display the binary representation of an integer
void show_bits(int n)
{
    printf("Binary: "); // Output label for the binary representation
    // Loop through each bit from 31 down to 0
    for (int bit = 31; bit >= 0; bit--)
    {
        // Shift the bits of n to the right and mask with 1 to get the current bit
        printf("%d", (n >> bit) & 1);
    }
    puts(""); // Print a newline after displaying all bits
}
