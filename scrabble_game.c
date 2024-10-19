#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
// Index corresponds to the letter's position: A=0, B=1, C=2, ..., Z=25
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function prototype for computing the score of a word
int compute_score(string word);

int main(void)
{
    // Prompt both players to enter their words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate the scores for both words using compute_score function
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine and print the winner based on the scores
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score1 < score2)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}

// Function to compute the score of a given word
int compute_score(string word)
{
    // Get the length of the input word
    int length = strlen(word);
    int letter, sum = 0; // Initialize letter index and score sum

    // Iterate through each character in the word
    for (int i = 0; i < length; i++)
    {
        // Check if the character is an uppercase letter
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            // Calculate the index for uppercase letters
            letter = word[i] - 'A';
        }
        // Check if the character is a lowercase letter
        else if (word[i] >= 'a' && word[i] <= 'z')
        {
            // Calculate the index for lowercase letters
            letter = word[i] - 'a';
        }
        // If the character is not a letter, skip to the next iteration
        else
            continue;
            
        // Add the points corresponding to the letter to the sum
        sum += POINTS[letter];
        letter = 0; // Reset letter index (optional)
    }
    // Return the total score of the word
    return sum;
}
