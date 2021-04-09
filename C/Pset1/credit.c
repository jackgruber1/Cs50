#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // As for credit card number
    long long card = 0;
    do
    {
        card = get_long_long("Number: ");
    }
    while (card < 0);

    // Check validity using Luhn's algorithm
    long long check = card;
    int sum = 0;

    // Iterate over all digits. If even, add to sum. If uneven, multiply by two and add to sum.
    for (int i = 0; check != 0; check /= 10, i++)
    {
        // Check if even
        if (i % 2 == 0)
        {
            sum += check % 10; // Modulo 10 extracts the last digit. Add to the sum
        }
        // Uneven
        else
        {
            int digit = (check % 10) * 2;
            sum += digit / 10 + digit % 10;
        }
    }

    // Check if the last digit of the sum is equal to 0 to see if valid, as per the algorithm
    if ((sum % 10) != 0)
    {
        printf("INVALID\n");
    }
    // If valid, check brand of the card by looking at length and first digits
    else
    {
        // AMEX
        if ((card >= 34e13 && card < 35e13) || (card >= 37e13 && card < 38e13))
        {
            printf("AMEX\n");
        }
        // Mastercard
        else if (card >= 51e14 && card < 56e14)
        {
            printf("MASTERCARD\n");
        }
        // VISA
        else if ((card >= 4e12 && card < 5e12) || (card >= 4e15 && card < 5e15))
        {
            printf("VISA\n");
        }
        // Invalid card
        else
        {
            printf("check that\n");
            printf("INVALID\n");
        }
    }
}
