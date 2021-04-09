#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask for pyramid height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height < 1 || height > 8);

    // Print pyramid
    for (int i = 0; i < height; i++)
    {
        // Print left half
        // Print empty spaces
        for (int k = 0; k < height - i - 1; k++)
        {
            printf(" ");
        }
        // Print left # blocks 
         for (int r = 0; r < i + 1; r++)
        {
            printf("#");
        }

        // Print two spaces
        printf("  ");

        // Print right half # blocks 
         for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
