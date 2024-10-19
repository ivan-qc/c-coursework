#include <stdio.h>
#include <string.h>

int main(void)
{
    // Array of strings (words) to search within
    char *words[] = {"battleship", "boot", "canon",
                     "iron", "thimble", "top hat"};
    char s[20]; // Declare a character array to hold user input

    printf("Word: "); // Prompt user to enter a word
    fgets(s, sizeof(s), stdin); // Read user input, including spaces, into array 's'
    s[strcspn(s, "\n")] = '\0'; // Remove the newline character from input (if present)

    // Loop through each word in the 'words' array
    for (int i = 0; i < 6; i++)
    {
        // Compare the current word with the user input
        if (strcmp(words[i], s) == 0)
        {
            // If a match is found, print the index of the word
            printf("Found inside: words[%i]\n", i);
            return 0; // Exit program with success
        }
    }

    puts("Not found"); // If no match is found, notify the user
    return 1; // Exit program with failure
}
