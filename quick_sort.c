#include<stdio.h>

//function to swap two elements
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to partition the array
int partition(int arr[] ,int low, int high)
{
    int j, i;
    int pivot = arr[high];//last element as pivot
    i = (low - 1); // index of the smaller element

    for(j = low; j <= high - 1; j++)
    {
        //if the current element is smaller than or equal to pivot
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);//swap arr[i] & arr[j]
        }
    }
    swap(&arr[i+1], &arr[high]);//swap arr[i+1] & arr[high]
    return (i + 1); //return index of the pivot element after partition
}

//funtion to perform quic sort
void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot_index = partition(arr, low, high);
        //recursively sort elements before and after the partition
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

int main()
{
    int n, i;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter the elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1); //0 for low parameter & n-1 for high parameter

    printf("\nSorted array is: ");
    for(i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0;
}

