#include <iostream>
using namespace std;

// Iterative implementation of binary search
int binaryIterative(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Key found
        }
        else if (arr[mid] > key) {
            high = mid - 1; // Search in the left half
        }
        else {
            low = mid + 1; // Search in the right half
        }
    }
    return -1; // Key not found
}

// Recursive implementation of binary search
int binaryRecursive(int arr[], int key, int low, int high) {
    if (low > high) {
        return -1; // Base case: key not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        return mid; // Key found
    }
    else if (key < arr[mid]) {
        return binaryRecursive(arr, key, low, mid - 1); // Search in the left half
    }
    else {
        return binaryRecursive(arr, key, mid + 1, high); // Search in the right half
    }
}

int main() {
    int arr[] = {2, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, choice;

    cout << "Enter the number to search: ";
    cin >> key;

    cout << "Choose search method:\n";
    cout << "1. Iterative Binary Search\n";
    cout << "2. Recursive Binary Search\n";
    cin >> choice;

    int result = -1;
    if (choice == 1) {
        result = binaryIterative(arr, size, key);
        if (result != -1) {
            cout << "Number found at index " << result << " using iterative binary search.\n";
        } else {
            cout << "Number not found using iterative binary search.\n";
        }
    }
    else if (choice == 2) {
        result = binaryRecursive(arr, key, 0, size - 1);
        if (result != -1) {
            cout << "Number found at index " << result << " using recursive binary search.\n";
        } else {
            cout << "Number not found using recursive binary search.\n";
        }
    }
    else {
        cout << "Invalid choice! Please enter 1 or 2.\n";
    }

    return 0;
}