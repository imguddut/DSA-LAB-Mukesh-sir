#include <iostream>
using namespace std;

// Function to perform binary search using recursion
int binarySearchRecursive(int arr[], int target, int low, int high) {
    if (low > high) {
        return -1; // Base case: target not found
    }

    int mid = low + (high - low) / 2; // Avoids overflow
    if (arr[mid] == target) {
        return mid; // Target found
    } else if (target < arr[mid]) {
        return binarySearchRecursive(arr, target, low, mid - 1); // Search in left half
    } else {
        return binarySearchRecursive(arr, target, mid + 1, high); // Search in right half
    }
}

int main() {
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value to search: ";
    int target;
    cin >> target;

    int low = 0;
    int high = n - 1;
    int result = binarySearchRecursive(arr, target, low, high);

    if (result == -1) {
        cout << "The value " << target << " does not exist in the array." << endl;
    } else {
        cout << "The value " << target << " is found at index " << result << "." << endl;
    }

    return 0;
}