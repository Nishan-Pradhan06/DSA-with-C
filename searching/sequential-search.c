// sequential search imolementation
#include <stdio.h>
#include <conio.h>
int linearsearch(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key) // if found then return index of the matched record
            return i;
    }
    return -1;
}
void main()
{
    int arr[] = {12, 45, 2, 7, 11, 54, 24, 65};
    int i, n = sizeof(arr) / sizeof(int);
    int key;
    printf("Enter a number you want to search: ");
    scanf("%d", &key);
    i = linearsearch(arr, n, key);
    if (i == -1) // if not found
        printf("%d is not exist in the list.", key);
    else
        printf("%d found at position %d", key, i + 1);
    getch();
}