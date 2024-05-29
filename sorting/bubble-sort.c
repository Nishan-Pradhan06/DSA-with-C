#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void bubblesort(int[], int);
void main()
{
    int arr[] = {2, 6, 4, 5,  8, 7, 9, 3};
    int i, n = sizeof(arr) / sizeof(int);
    printf("Before sorting.....\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    bubblesort(arr, n);

    printf("\nAfter sorting..........\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    
}

void bubblesort(int arr[], int n)
{
    int i, j, temp;
    // total number of pass is n-1
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++) //total number of comaparisaon in each pass in n-1
        {
            if (arr[j]>arr[j + 1]) //if number are not in proper position then swap
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}