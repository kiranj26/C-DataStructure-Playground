/**
 * Template for Splitting an Array into Two Equal Sum Subarrays
 *
 * This C program template provides the structure for splitting an array into two equal
 * subarrays such that the sum of both parts is equal.
 *
 * The main logic to achieve the equal split is implemented in the `splitArrayEqualSum` function.
 *
 * Example Usage:
 * int arr[] = {1, 5, 11, 5};
 * int n = sizeof(arr) / sizeof(arr[0]);
 * splitArrayEqualSum(arr, n);
 */

#include <stdio.h>
#include <stdbool.h>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Efficient Solution to split the array into two equal sum subarrays
 *
 * The approach is to compute the total sum of the array and then traverse the array,
 * maintaining a running sum from the left. At each step, the right sum can be
 * calculated by subtracting the left sum from the total sum. If at any point,
 * the left sum equals the right sum, we have found the split point.
 */
bool splitArrayEqualSum(int arr[], int n) {
    int totalSum = 0;

    // Calculate total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int leftSum = 0;

    // Traverse the array to find the split point
    for (int i = 0; i < n - 1; i++) {
        leftSum += arr[i];
        int rightSum = totalSum - leftSum;

        if (leftSum == rightSum) {
            // Print left subarray
            printf("Left Array: ");
            for (int k = 0; k <= i; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");

            // Print right subarray
            printf("Right Array: ");
            for (int k = i + 1; k < n; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");

            return true;
        }
    }

    return false;
}

int main() {
    // Test case 1: Array with an equal split possible
    int arr1[] = {1, 5, 11, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // Test case 2: Array with an equal split possible
    int arr2[] = {1, 1, 1, 2, 1, 1, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Test case 3: Array without an equal split possible
    int arr3[] = {1, 2, 3, 4, 5, 6};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    // Additional Test case 4: Array with negative numbers
    int arr4[] = {3, -1, 1, 2, -1, 3};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    // Additional Test case 5: Array with zero elements
    int arr5[] = {0, 0, 0, 0};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);

    int *testCases[] = {arr1, arr2, arr3, arr4, arr5};
    int testCaseSizes[] = {n1, n2, n3, n4, n5};
    int numTestCases = sizeof(testCaseSizes) / sizeof(testCaseSizes[0]);

    for (int t = 0; t < numTestCases; t++) {
        int *arr = testCases[t];
        int n = testCaseSizes[t];

        printf("Test case %d:\n", t + 1);
        printf("Original array: ");
        printArray(arr, n);

        // Call the function to split the array
        if (splitArrayEqualSum(arr, n)) {
            printf("Array successfully split into two equal sum subarrays.\n");
        } else {
            printf("The array cannot be split into two equal sum subarrays.\n");
        }

        printf("\n");
    }

    return 0;
}
