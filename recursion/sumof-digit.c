// wap to calcaulate sum of digit of a numner using recursion

#include <stdio.h>
#include <conio.h>
int digitSum(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return n % 10 + digitSum(n / 10);
    }
}

void main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\nThe sum of digits of %d is : %d\n", n, digitSum(n));
    getch();
}