#include <stdio.h>

#define MAX_SIZE 100

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int *n) {
    if (*n >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    int pos, element;
    printf("Enter position (1 to %d): ", *n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > *n + 1) {
        printf("Invalid position.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &element);

    // Shift elements to the ri
