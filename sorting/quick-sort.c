#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int arr[] = {7, 3, 9, 2, 8, 4};
    int i, n = sizeof(arr) / sizeof(int);
    printf("Before Sorting..........\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nAfter Sorting...............\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    getch();
}

void quickSort(int arr[], int lb, int ub)
{
    int down = lb, up = ub, pivot = arr[lb], temp;
    while (down < up) // if there are at least z elements
    {
        pivot = arr[lb]; // make first element as pivot element
        down = lb;
        up = ub;
        while (down < ub && arr[down] <= pivot) // increase down until larger element i
        {
            down++;
        }
        while (arr[up] > pivot) // decrese up utill smaller or equal to pivot
        {
            up--;
        }
        if (down < up)
        {
            temp = arr[down];
            arr[down] = arr[up];
            arr[up] = temp;
        }
        else
        {
            temp = arr[lb];
            arr[lb] = arr[up];
            arr[up] = temp;
            quickSort(arr, lb, up - 1); // sort the list of smaller elements using quick
            quickSort(arr, up + 1, ub); // sort the list of bogger elements using quick
        }
    }
}

// #include <stdio.h>
// #include <stdlib.h>

// void quickSort(int arr[], int lb, int ub);

// void main()
// {
//     int arr[] = {7, 3, 9, 2, 8, 4};
//     int i, n = sizeof(arr) / sizeof(int);
//     printf("Before Sorting..........\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d\t", arr[i]);
//     }

//     quickSort(arr, 0, n - 1);

//     printf("\nAfter Sorting...............\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d\t", arr[i]);
//     }

//     getchar();
// }

// void quickSort(int arr[], int lb, int ub)
// {
//     int down, up, pivot, temp;
//     if (lb < ub)
//     {
//         pivot = arr[lb];
//         down = lb;
//         up = ub;
//         while (down < up)
//         {
//             while (arr[down] <= pivot && down < ub)
//             {
//                 down++;
//             }
//             while (arr[up] > pivot)
//             {
//                 up--;
//             }
//             if (down < up)
//             {
//                 temp = arr[down];
//                 arr[down] = arr[up];
//                 arr[up] = temp;
//             }
//         }
//         temp = arr[lb];
//         arr[lb] = arr[up];
//         arr[up] = temp;

//         quickSort(arr, lb, up - 1);
//         quickSort(arr, up + 1, ub);
//     }
// }