#include<stdio.h>

void selectionSort(int arr[], int n)
{
    int i, j, start, temp;

    for(i = 0; i < n - 1; i++)
    {
        start = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[start])
            {
                start = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[start];
        arr[start] = temp;
    }
}

int main()
{
    int i, n;

    printf("\nEntet the number of elements of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter the %d elements: \n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOrriginal array is: ");
    for(i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    selectionSort(arr, n);

    printf("\nSorted array is: ");
    for(i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0;
}