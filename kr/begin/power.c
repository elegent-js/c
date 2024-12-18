#include <stdio.h>

/**
 * prototype: program to calculate power of a number
 */
int power(int, int);


int main(int argc, char *argv[])
{
    int x, y;
    printf("Enter the number: ");
    scanf("%d", &x);
    printf("Enter the power: ");
    scanf("%d", &y);
    printf("%d^%d = %d\n", x, y, power(x, y));
    return 0;
}

int power(int x, int y)
{
    int i, result = 1;
    for (i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}