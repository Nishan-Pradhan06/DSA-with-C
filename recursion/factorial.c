// wap to find the factorical from recurtion..

#include <stdio.h>
#include <conio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

void main()
{
    int i, num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d! is %d", num, factorial(num));
    getch();
}