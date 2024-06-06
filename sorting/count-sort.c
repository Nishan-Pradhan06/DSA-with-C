// non comparision based sortring technique

#include <stdio.h>
#include <conio.h>
#define SIZE 15
#define MAXVALUE 21
int getHighestNumber(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        return max;
    }
}

void countSort(int arr[], int n)
{
    int count[MAXVALUE] = {0}; // create a count array with initial value of zero
    int temp[SIZE];
    int k = getHighestNumber(arr, n);
    int i;
    // perform frequency count of each number in the array
    for (i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    // then calcualte cumulative frequencey
    for (i = 1; i <= k; i++)
    {
        count[i] += count[i - 1]; // count [i] = count [i] + count[i-1];
    }
    // now start the intems and put into temp array;
    for (i = n - 1; i < 0; i--)
    {
        temp[--count[arr[i]]] = arr[i];
    }

    // finally copy back the temp into arr
    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}
void main()
{
    int arr[] = {7, 5, 4, 9, 2, 4, 7, 2, 1, 9};
    int i, n = sizeof(arr) / sizeof(int);
    printf("Before sorting.......\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    countSort(arr, n);
    printf("After sorting.......\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    getch();
}