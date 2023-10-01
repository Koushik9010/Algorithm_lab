**Bubble Sort**
#include<stdio.h>

void bubbleSort(int arr[], int n)
{
    int temp;
    int  i, j;
    for(i = 0; i < n -1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int i, n;

    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter the array elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nSorted array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    printf("\n\n");
    return 0;
}

**Linear search**
#include<stdio.h>

int array;
int i;
int n;

int search(int array[], int value)
{
    for(i = 0; i < n; i++)
    {
        if(array[i] == value)
        {
            printf("The position of the value is %d", i+1);
        }
    }
}

int main()
{
    int value;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n];

    printf("Enter the value of the array: ");
    for(i = 0; i < n; i++);
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the value want to search: ");
    scanf("%d", &value);

    search(array, value);
}

**Selection sort**
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

**Heap sort**
#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at given index
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max heap from the array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Move the current root to the end
        heapify(arr, i, 0);     // Call heapify on the reduced heap
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
