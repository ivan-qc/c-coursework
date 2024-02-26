#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main(void)
{
    // Initialization and declaration
    float coleman_liau = 0.0;
    int index = 0, letters = 0, sentences = 0, words = 0;

    // Gets text from the user
    string text = get_string("Text: ");

    // Update variables with the return value of each function
    letters = count_letters(text);
    sentences = count_sentences(text);
    words = count_words(text);

    // Updates coleman_liau formula using the updated variables
    coleman_liau = 0.0588 * ((float) letters / words * 100) - 0.296 * ((float) sentences / words * 100) - 15.8;

    // Updates index to the nearest whole number
    index = (int) round(coleman_liau);

    if (index < 1)
    {
        puts("Before Grade 1");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        puts("Grade 16+");
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    words++;
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}
