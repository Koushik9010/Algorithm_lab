#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is found, return its index
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // If the target is not found, return -1
    return -1;
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d sorted elements in ascending order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
