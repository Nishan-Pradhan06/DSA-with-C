// wap to calcualte the sum of n number using recursion
#include <stdio.h>
#include <conio.h>
iterative solution
int sum1(int n)
{
    int s = 0, i;
    for (i = 1; i < = n; i++)
    {
        s += 1;
    }
    return s;
}

// recurcive soluiton
int sum(int n)
{
    // if(n<0)
    //     return 0; for negeative number handling
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + sum(n - 1);
    }
}

void main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Sum of %d number is:%d", num, sum(num));
    getch();
}