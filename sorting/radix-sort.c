#include<stdio.h>
#include <stdio.h>
#define MAX 20

// Function to get the highest number in the array
int getHighestNumber(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Function to count the number of digits in a number
int getDigitCount(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

// Function to perform counting sort based on the digit represented by place
void countSort(int arr[], int n, int place)
{
    int count[10] = {0};
    int temp[MAX];

    // Calculate count of elements
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / place) % 10]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; i--)
    {
        temp[--count[(arr[i] / place) % 10]] = arr[i];
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

// Main function to implement radix sort
void radixSort(int arr[], int n)
{
    int max = getHighestNumber(arr, n);
    int digitCount = getDigitCount(max);
    int place = 1;

    for (int i = 0; i < digitCount; i++)
    {
        countSort(arr, n, place);
        place *= 10;
    }
}

int main()
{
    int arr[] = {77, 82, 38, 15, 108, 20, 39, 11, 51, 49};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting ......\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    radixSort(arr, n);

    printf("\nAfter sorting .......\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
