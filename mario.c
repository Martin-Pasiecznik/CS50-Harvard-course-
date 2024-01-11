///implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:
///       #
///      ##
///     ###
#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int steps;
    do
    {
        steps = get_int("Number of steps");
    }
    while (steps < 1);
    int blank_space = 0;
    for (int i = 1; i <= steps; i++)
    {
        while (blank_space < steps)
        {
            // leaves blank space before each step
            printf(" ");
            blank_space++;
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
        // reduce the blank space each iteration.
        blank_space = i;
    }
}
