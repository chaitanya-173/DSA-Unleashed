#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i in Max-Heap
void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapifyMax(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Function to heapify a subtree rooted with node i in Min-Heap
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&arr[smallest], &arr[i]);
        heapifyMin(arr, n, smallest); // Recursively heapify the affected subtree
    }
}

// Function to perform Heap Sort in Max-Heap (descending order)
void heapSortMax(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }

    // Extract elements one by one
    while (n > 1) {
        swap(&arr[0], &arr[n - 1]); // Swap root with last element
        n--;
        heapifyMax(arr, n, 0); // Heapify the root element
    }
}

// Function to perform Heap Sort in Min-Heap (ascending order)
void heapSortMin(int arr[], int n) {
    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }

    // Extract elements one by one
    while (n > 1) {
        swap(&arr[0], &arr[n - 1]); // Swap root with last element
        n--;
        heapifyMin(arr, n, 0); // Heapify the root element
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {6, 3, 9, 1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Printing Unsorted array:\n");
    printArray(arr, size);

    // Sorting in descending order (Max-Heap)
    heapSortMax(arr, size);
    printf("Printing sorted array in ascending order:\n");
    printArray(arr, size);

    // Sorting in ascending order (Min-Heap)
    // Re-initialize the array for the next sort
    int arrMin[] = {6, 3, 9, 1, 8};
    size = sizeof(arrMin) / sizeof(arrMin[0]);
    heapSortMin(arrMin, size);
    printf("Printing sorted array in descending order:\n");
    printArray(arrMin, size);

    return 0;
}
