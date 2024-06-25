/*
This C program demonstrates how to delete an element from an array.

The algorithm works as follows:

1. The deleteElement function is called with the array, its size, and the position of the element to be deleted as arguments.

2. Inside the deleteElement function, it first checks if the given position is valid. If the position is less than 0 or greater than or equal to the size of the array, it prints an error message and returns without doing anything.

3. If the position is valid, it enters a loop that starts from the given position and goes up to the second last element of the array. Inside the loop, each element of the array is replaced by the next element. This effectively "deletes" the element at the given position by shifting all the elements after it one position to the left.

4. After the loop, the size of the array is decreased by 1 to reflect the deletion of the element.

5. The main function then prints the array after the deletion.

6. The program also includes some test cases where it deletes elements at specific positions and prints the array after each deletion.
*/

#include <stdio.h>

// Function to delete an element from the array
void deleteElement(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

// Function to print the array
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Initial array
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10; // Size of the array

    // Test cases
    const int testCases[] = {2, 4, 0}; // Positions to delete
    const int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    printf("Original array: ");
    printArray(arr, n);

    for (int i = 0; i < numTestCases; i++) {
        int pos = testCases[i];
        printf("Deleting element at position %d:\n", pos);
        deleteElement(arr, &n, pos);
        printf("Array after deletion: ");
        printArray(arr, n);
    }

    return 0;
}
