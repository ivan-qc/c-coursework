#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Function prototypes for counting letters, words, and sentences
int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main(void)
{
    // Initialize variables for the Coleman-Liau index calculation
    float coleman_liau = 0.0; // Holds the calculated index value
    int index = 0; // Index to hold the final grade level
    int letters = 0; // Counter for the number of letters
    int sentences = 0; // Counter for the number of sentences
    int words = 0; // Counter for the number of words

    // Prompt user for input text
    string text = get_string("Text: ");

    // Count letters, sentences, and words in the input text
    letters = count_letters(text);
    sentences = count_sentences(text);
    words = count_words(text);

    // Calculate the Coleman-Liau index using the formula
    coleman_liau = 0.0588 * ((float) letters / words * 100) - 
                   0.296 * ((float) sentences / words * 100) - 15.8;

    // Round the index to the nearest whole number
    index = (int) round(coleman_liau);

    // Output the grade level based on the calculated index
    if (index < 1)
    {
        puts("Before Grade 1"); // Output for grades lower than 1
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %d\n", index); // Output for grades 1 to 15
    }
    else
    {
        puts("Grade 16+"); // Output for grades 16 and above
    }
}

// Function to count the number of letters in the text
int count_letters(string text)
{
    int letters = 0; // Initialize letter counter
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check if the character is an alphabetic letter
        if (isalpha(text[i]))
        {
            letters++; // Increment letter counter
        }
    }
    return letters; // Return the total count of letters
}

// Function to count the number of words in the text
int count_words(string text)
{
    int words = 0; // Initialize word counter
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Increment word count for each space character
        if (text[i] == 32)
        {
            words++;
        }
    }
    words++; // Increment for the last word (after the final space)
    return words; // Return the total count of words
}

// Function to count the number of sentences in the text
int count_sentences(string text)
{
    int sentences = 0; // Initialize sentence counter
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Increment sentence count for end punctuation marks
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences; // Return the total count of sentences
}
