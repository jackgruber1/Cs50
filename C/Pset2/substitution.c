#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

bool ValidKey(string key);

int main(int argc, string argv[])
{
    // Get key
    string key = argv[1];

    // Ensure only two arguments are provided
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (ValidKey(key))
    {
         // Get text from user
        string text = get_string("plaintext: ");

        // Generate cipher
        printf("ciphertext: ");
        for (int i = 0; i < strlen(text); i++)
        {
            if (isalpha(text[i]))
            {
                if (isupper(text[i]))
                {
                    printf("%c", toupper(key[text[i] - 'A'])); // Substract 'A' to generate correct index in the cipher.
                }
                else
                {
                    printf("%c", tolower(key[text[i] - 'a'])); // Same as above. Similar to scrabble problem
                }
            }
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
}


// Works
bool ValidKey(string key)
{
    // Check key length
    if (strlen(key) < 26)
    {
        return false;
    }
    // Check for non-alphanumeric characters and repeated characters
    int freq[26] = { 0 }; // create array to count instances of each character
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == false)
        {
            return false;
        }
        // Check for repeated occurence of characters
        int index = toupper(key[i] - 'A'); // locate appropiate index on array
        freq[index]++; // Count each occurence of character
        if (freq[index] > 1)
        {
            return false; // if character has been repeated, return false
        }
    }
    return true;
}
