/**
 * Insert a new value into an array at a specified position
 *
 * This program demonstrates how to insert a new value into a given array
 * at a specified position. The function `insert_array` inserts the new value
 * by shifting the elements to the right and placing the new value at the desired
 * position. The `main` function tests the insertion with different test cases.
 *
 * Note: The array size is fixed, and this example does not handle dynamic resizing.
 */

#include <stdio.h>
#include <stdlib.h>

// Function to insert a new value into the array at the specified position
void insert_array(int arr[], int size, int new_val, int position) {
    // Check for valid position
    if (position > size || position < 0) {
        printf("Invalid position\n");
        return;
    }

    // Shift elements to the right
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new value
    arr[position] = new_val;
}

// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test case 1
    int arr1[6] = {0, 1, 2, 3, 4, 0}; // Extra space for new element
    int new_val1 = 10;
    int position1 = 2;

    printf("Test case 1 - Before insertion:\n");
    print_array(arr1, 5); // Print original array
    insert_array(arr1, 5, new_val1, position1); // Insert new value
    printf("Test case 1 - After insertion:\n");
    print_array(arr1, 6); // Print updated array

    // Test case 2
    int arr2[6] = {0, 1, 2, 3, 4, 0}; // Extra space for new element
    int new_val2 = 20;
    int position2 = 0;

    printf("\nTest case 2 - Before insertion:\n");
    print_array(arr2, 5); // Print original array
    insert_array(arr2, 5, new_val2, position2); // Insert new value
    printf("Test case 2 - After insertion:\n");
    print_array(arr2, 6); // Print updated array

    // Test case 3
    int arr3[6] = {0, 1, 2, 3, 4, 0}; // Extra space for new element
    int new_val3 = 30;
    int position3 = 5;

    printf("\nTest case 3 - Before insertion:\n");
    print_array(arr3, 5); // Print original array
    insert_array(arr3, 5, new_val3, position3); // Insert new value
    printf("Test case 3 - After insertion:\n");
    print_array(arr3, 6); // Print updated array

    return 0;
}
