#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void SelectionSort(int[], int);
int getSmallestPosition(int[], int, int);

void main()
{
    int arr[] = {12, 43, 54, 11, 44, 77, 2, 34, 55, 66};
    int i, n = sizeof(arr) / sizeof(int);

    printf("Before Sorting..........\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    SelectionSort(arr, n);

    printf("\nAfter Soring..............\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    getch();
}

int getSmallestPosition(int arr[], int i, int j)
{
    int pos = i;
    for (int k = i + 1; k <= j; k++)
    {
        if (arr[k] < arr[pos])
        {
            pos = k;
        }
    }
    return pos;
}

void SelectionSort(int arr[], int n)
{
    int i, smallestPosition, temp;

    for (i = 0; i < n - 1; i++)
    {
        smallestPosition = getSmallestPosition(arr, i, n - 1);
        temp = arr[i];
        arr[i] = arr[smallestPosition];
        arr[smallestPosition] = temp;
    }
}
