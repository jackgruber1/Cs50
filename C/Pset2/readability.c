#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    // User input
    string text = get_string("Text: ");

    // Initialize counters
    int characters = 0;
    int words = 0;
    int sentences = 0;

    // Count
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Count characters
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            characters++;
        }
        // Count words
        if (characters == 1) //This corrects for the fact that the first word is not counted.
        {
            words++;
        }
        if (text[i] == ' ' && ((text[i + 1] >= 'a' && text[i + 1] <= 'z') || (text[i + 1] >= 'A' && text[i + 1] <= 'Z')))
        {
            words++;
        }
        // Count sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    //Calculate Coleman-Liau Index
    float L = (100.0 * (float) characters / (float) words);
    float S = (100.0 * (float) sentences / (float) words);
    float index = 0.0588 * L - 0.296 * S - 15.8;



    //Print result
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        //Round and convert to int before printing
        int index_int = round(index);
        printf("Grade %i\n", index_int);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
