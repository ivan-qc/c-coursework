#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string cipher(string plaintext, string arr[]);
string lowered(string arr[], int size);

int main(int argc, string argv[])
{
    // Catches no command-line argument
    if (argc != 2)
    {
        printf("Usage: ./subs key\n");
        return 1;
    }
    // Catches invalid key length
    int length = strlen(argv[1]);
    if (length != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    // Catches no alphabetic or repeated characters inside key
    if (length == 26)
    {
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must be alphabetic\n");
                return 1;
            }
        }
        // Lowers key
        lowered(argv, argc);
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            for (int j = i + 1; argv[1][j] != '\0'; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Key must contain each letter exactly once\n");
                    return 1;
                }
            }
        }
    }
    // Prompt the user and return encryption
    string text = get_string("plaintext: ");
    printf("ciphertext: %s\n", cipher(text, argv));
    return 0;
}

// Encryption function
string cipher(string plaintext, string arr[])
{
    char capital[2];
    capital[1] = '\0';
    int index;
    int length = strlen(plaintext);
    char *ciphered = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                index = plaintext[i] - 'A';
                capital[0] = toupper(arr[1][index]);
                strncat(ciphered, &capital[0], 1);
            }
            else if (islower(plaintext[i]))
            {
                index = plaintext[i] - 'a';
                strncat(ciphered, &arr[1][index], 1);
            }
        }
        else
        {
            strncat(ciphered, &plaintext[i], 1);
            continue;
        }
    }
    return ciphered;
}

// Function to convert a string to lower case
string lowered(string arr[], int size)
{
    for (int i = 0; arr[1][i] != '\0'; i++)
    {
        arr[1][i] = tolower(arr[1][i]);
    }
    return arr[1];
}