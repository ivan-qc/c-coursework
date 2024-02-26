#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    // Ask number
    long card_number;
    do
    {
        printf("Number: ");
        scanf("%ld", &card_number);
    }
    while (card_number <= 0);

    // Backup original card_number for the First two digits block
    long first_two = card_number;

    // Luhn's Algorithm
    int digit, count;
    int total_digits = 0;
    int sum = 0;
    bool shouldDouble = false;
    while (card_number != 0)
    {
        digit = card_number % 10;
        card_number = card_number / 10;

        if (shouldDouble)
        {
            count = digit * 2;
            if (count > 9)
                sum += count % 10 + count / 10;
            else
                sum += count;
        }
        else
            sum += digit;

        shouldDouble = !shouldDouble;
        total_digits++;
    }

    // Gives first two digits ONLY if card is valid and length between 13-16 otherwise INVALID
    while (first_two >= 100 && sum % 10 == 0 && total_digits >= 13 && total_digits <= 16)
        first_two = first_two / 10;

    // Prints creditor according to its length and format
    if ((first_two == 34 || first_two == 37) && total_digits == 15)
        printf("AMEX\n");
    else if (first_two > 39 && first_two < 50 && total_digits >= 13 && total_digits <= 16)
        printf("VISA\n");
    else if (first_two > 50 && first_two < 56 && total_digits == 16)
        printf("MASTERCARD\n");
    else
        printf("INVALID\n");
}