#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] < key)
            low = mid + 1; 
        else
            high = mid - 1; 
    }

    return -1; 
}

int main() {
    int arr[100], n, key, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (for binary search, ensure they are sorted):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("\nChoose search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = linearSearch(arr, n, key);
            if (result == -1)
                printf("Element not found using Linear Search.\n");
            else
                printf("Element found at position %d using Linear Search.\n", result + 1);
            break;

        case 2:
            result = binarySearch(arr, n, key);
            if (result == -1)
                printf("Element not found using Binary Search.\n");
            else
                printf("Element found at position %d using Binary Search.\n", result + 1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
