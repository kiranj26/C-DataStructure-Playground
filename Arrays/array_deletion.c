/*
This C program demonstrates how to delete an element from an array.

The algorithm works as follows:

1. The user is asked to input the position of the element they want to delete from the array.

2. The deleteElement function is called with the array, its size, and the position of the element to be deleted as arguments.

3. Inside the deleteElement function, first, it checks if the given position is valid. If the position is less than 0 or greater than or equal to the size of the array, it prints an error message and returns without doing anything.

4. If the position is valid, it enters a loop that starts from the given position and goes up to the second last element of the array. Inside the loop, each element of the array is replaced by the next element. This effectively "deletes" the element at the given position by shifting all the elements after it one position to the left.

5. After the loop, the size of the array is decreased by 1 to reflect the deletion of the element.

6. The main function then prints the array after the deletion.

7. The program also includes some test cases where it deletes elements at specific positions and prints the array after each deletion.
*/

#include <stdio.h>

// Function to find the position of an element in the array
int findPosition(int arr[], int n, int element) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

// Function to delete an element from the array
void deleteElement(int arr[], int *n, int pos) {
    int i;
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }
    for (i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10; // Size of the array
    int pos, i;

    printf("Enter the position of the element to delete: ");
    scanf("%d", &pos);

    // Delete the element at the given position
    deleteElement(arr, &n, pos);

    printf("Array after deletion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Test cases
    printf("Test cases:\n");
    printf("Deleting element at position 3:\n");
    deleteElement(arr, &n, 2);
    printf("Array after deletion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Deleting element at position 5:\n");
    deleteElement(arr, &n, 4);
    printf("Array after deletion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}