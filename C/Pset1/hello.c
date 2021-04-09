#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get name from user and greet
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}
