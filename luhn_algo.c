#include <stdbool.h>
#include <stdio.h>

// Declare a variable to store the card number
    long card_number;

    // Prompt the user for a valid card number until a positive value is entered
    do
    {
        printf("Number: ");
        scanf("%ld", &card_number);
    }
    while (card_number <= 0); // Repeat if the entered number is not positive

    // Store the original card number for later use in identifying the issuer
    long first_two = card_number;

    // Variables for Luhn's Algorithm implementation
    int digit, count;
    int total_digits = 0; // Count of total digits in the card number
    int sum = 0; // Accumulator for the sum of processed digits
    bool shouldDouble = false; // Flag to indicate whether to double the next digit

    // Process the card number for Luhn's Algorithm
    while (card_number != 0)
    {
        digit = card_number % 10; // Extract the last digit
        card_number = card_number / 10; // Remove the last digit from the card number

        // If the flag indicates to double the digit
        if (shouldDouble)
        {
            count = digit * 2; // Double the digit
            // Add the digits of the doubled value to the sum
            if (count > 9)
                sum += count % 10 + count / 10; // If greater than 9, add the two digits
            else
                sum += count; // Otherwise, just add the doubled value
        }
        else
            sum += digit; // Add the digit as is

        // Toggle the flag for the next iteration
        shouldDouble = !shouldDouble;
        total_digits++; // Increment the digit count
    }

    // Check if the card number is valid by Luhn's Algorithm, and get the first two digits
    while (first_two >= 100 && sum % 10 == 0 && total_digits >= 13 && total_digits <= 16)
        first_two = first_two / 10; // Reduce first_two to the first two digits

    // Identify the card issuer based on the first two digits and total digit count
    if ((first_two == 34 || first_two == 37) && total_digits == 15)
        printf("AMEX\n"); // American Express
    else if (first_two > 39 && first_two < 50 && total_digits >= 13 && total_digits <= 16)
        printf("VISA\n"); // Visa
    else if (first_two > 50 && first_two < 56 && total_digits == 16)
        printf("MASTERCARD\n"); // MasterCard
    else
        printf("INVALID\n"); // If none match, the card is invalid
}
