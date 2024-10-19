#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
string cipher(string plaintext, string arr[]);
string lowered(string arr[], int size);

int main(int argc, string argv[])
{
    // Check if the correct number of command-line arguments is provided
    if (argc != 2)
    {
        printf("Usage: ./subs key\n"); // Display usage instructions
        return 1; // Exit with an error code
    }
    
    // Check the length of the key
    int length = strlen(argv[1]);
    if (length != 26)
    {
        printf("Key must contain 26 characters\n"); // Key must be 26 characters long
        return 1; // Exit with an error code
    }
    
    // Validate that the key contains only alphabetic characters and no duplicates
    if (length == 26)
    {
        // Check if all characters in the key are alphabetic
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must be alphabetic\n"); // Key contains non-alphabetic characters
                return 1; // Exit with an error code
            }
        }
        
        // Convert the key to lowercase for uniformity
        lowered(argv, argc);
        
        // Check for duplicate characters in the key
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            for (int j = i + 1; argv[1][j] != '\0'; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must contain each letter exactly once\n"); // Duplicate found
                    return 1; // Exit with an error code
                }
            }
        }
    }

    // Prompt the user for plaintext input
    string text = get_string("plaintext: ");
    // Encrypt the plaintext and print the ciphertext
    printf("ciphertext: %s\n", cipher(text, argv));
    return 0; // Exit successfully
}

// Encryption function
string cipher(string plaintext, string arr[])
{
    char capital[2]; // Array to hold a single character for uppercase conversion
    capital[1] = '\0'; // Null-terminate the character array
    int index; // Variable to hold the index of the character in the alphabet
    int length = strlen(plaintext); // Length of the plaintext
    char *ciphered = malloc((length + 1) * sizeof(char)); // Allocate memory for the ciphertext

    // Iterate through each character in the plaintext
    for (int i = 0; i < length; i++)
    {
        // Check if the character is alphabetic
        if (isalpha(plaintext[i]))
        {
            // Handle uppercase characters
            if (isupper(plaintext[i]))
            {
                index = plaintext[i] - 'A'; // Calculate the index for the uppercase letter
                capital[0] = toupper(arr[1][index]); // Get the corresponding uppercase character from the key
                strncat(ciphered, &capital[0], 1); // Append the character to the ciphertext
            }
            // Handle lowercase characters
            else if (islower(plaintext[i]))
            {
                index = plaintext[i] - 'a'; // Calculate the index for the lowercase letter
                strncat(ciphered, &arr[1][index], 1); // Append the corresponding lowercase character to the ciphertext
            }
        }
        else
        {
            // If the character is not alphabetic, append it directly to the ciphertext
            strncat(ciphered, &plaintext[i], 1);
            continue; // Skip to the next character
        }
    }
    return ciphered; // Return the resulting ciphertext
}

// Function to convert the key to lowercase
string lowered(string arr[], int size)
{
    for (int i = 0; arr[1][i] != '\0'; i++)
    {
        arr[1][i] = tolower(arr[1][i]); // Convert each character in the key to lowercase
    }
    return arr[1]; // Return the modified key
}
