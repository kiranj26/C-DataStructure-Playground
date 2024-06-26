/**
 * Check if subarray with given product exists in an array
 *
 * Given an array of both positive and negative integers and a number K,
 * this function checks if any subarray with product K is present in the array.
 *
 * Example Usage:
 * int arr[] = {-2, -1, 3, -4, 5};
 * int n = sizeof(arr) / sizeof(arr[0]);
 * int K = 2;
 * bool result = isSubarrayWithProductK(arr, n, K);
 * assert(result == true);
 */

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

// Function to check if a subarray with given product exists
bool isSubarrayWithProductK(int arr[], int n, int K) {
    // Edge case: if K is 0, we need to check if there's a zero in the array
    if (K == 0) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                return true;
            }
        }
        return false;
    }

    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = i; j < n; j++) {
            product *= arr[j];
            if (product == K) {
                return true;
            }
        }
    }
    return false;
}

// Function to print test result
void printTestResult(int arr[], int n, int K, bool expected) {
    bool result = isSubarrayWithProductK(arr, n, K);
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nProduct K: %d\nExpected: %s\nResult: %s\n\n", K, expected ? "YES" : "NO", result ? "YES" : "NO");
    assert(result == expected);
}

int main() {
    // Test case 1
    int arr1[] = {-2, -1, 3, -4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int K1 = 2;
    printTestResult(arr1, n1, K1, true);

    // Test case 2
    int arr2[] = {3, -1, -1, -1, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int K2 = 3;
    printTestResult(arr2, n2, K2, true);

    // Test case 3: No subarray with product K
    int arr3[] = {1, 2, 3, 4, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int K3 = 50;
    printTestResult(arr3, n3, K3, false);

    // Test case 4: Single element with product K
    int arr4[] = {2};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int K4 = 2;
    printTestResult(arr4, n4, K4, true);

    // Test case 5: Array with negative numbers
    int arr5[] = {1, -1, 2, -2, 3};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int K5 = -2;
    printTestResult(arr5, n5, K5, true);

    return 0;
}
