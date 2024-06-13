#include <stdio.h>
#include <conio.h>
void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void heapify(int arr[], int n, int i)
{
    int left, right, max;
    left = i * 2 + 1;                       // index of left  child
    right = i * 2 + 2;                      // index of right child in the array
    max = i;                                // initially assuming that parent child is bigger
    if (left < n && arr[max] < arr[left])   // if left child is bigger than parent
        max = left;                         // make left child as max
    if (right < n && arr[max] < arr[right]) // if right child is bigger than the parent or
        max = right;                        // make right child as max
    if (max != i)                           // if paremt is not bigger than its children then
    {
        swap(&arr[i], &arr[max]); // exchange parent with max child
        heapify(arr, n, max);     // recursively call heapify on child subtree
    }
}
void heapsort(int arr[], int n)
{
    int i;
    // first create a max heap of array
    for (i = n / 2; i >= 0; i--) // lets do from the last internal node to root node one by one
    {
        heapify(arr, n, i);
    }
    // swapping root node to last node
    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]); // swapping the value of root and last child
        heapify(arr, i, 0);     // heapify root node again once more
    }
}
void main()
{
    int arr[] = {1, 7, 5, 9, 13, 2, 11, 3, 5};
    int i, n = sizeof(arr) / sizeof(int);
    printf("Before sorting.............\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    heapsort(arr, n);
    printf("\nAfter sorting..............\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    getch();
}