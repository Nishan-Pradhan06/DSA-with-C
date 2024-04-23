// wap to generate nth term of fibinacci sequence using recursion
// 0,1,1,2,3,5,7,13...nth term

#include <stdio.h>
#include <conio.h>

int fib(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fib(n - 2) + fib(n - 1);
    }
}

void main()
{
    int num, i;
    printf("Enter the how many term you want ?: ");
    scanf("%d", &num);
    printf("fibinacci series: ");
    for (i = 1; i <= num; i++)
    {
        printf("%d\t", fib(i));
    }
    getch();
}