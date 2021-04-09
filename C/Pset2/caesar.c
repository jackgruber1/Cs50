#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


void encrypt(int k);

// Get cipher key from user
int main(int argc, string argv[])
{
    // Check that only one argument is provided
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check that input from user is numerical
    // For this, check if each individual character is a digit.
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the input from user to integer
    int key = atoi(argv[1]);

    // Apply cipher function
    encrypt(key);
}


void encrypt(int k)
{
    // Get plain text from user
    string plainstring = get_string("plaintext: ");

    printf("ciphertext: ");


    // Apply Caesar (add k to each ASCII value) cipher to each character
    for (int i = 0, n = strlen(plainstring); i < n; i++)
    {
        // Apply cipher to lower case characters.
        // Need to subtract ASCII "a" (97) integer value and use formula so that it doesn't map to a non-alphabetic character
        if (islower(plainstring[i]))
        {
            char p_i = plainstring[i] - 97;
            char c_i = (p_i + k) % 26;
            printf("%c", c_i + 97);
        }
        // Apply cipher to upper case characters
        else if (isupper(plainstring[i]))
        {
            char p_i = plainstring[i] - 65;
            char c_i = (p_i + k) % 26;
            printf("%c", c_i + 65);
        }
        // Leave non-alphabetic characters the same
        else
        {
            printf("%c", plainstring[i]);
        }
    }
    // Print new line
    printf("\n");
}
