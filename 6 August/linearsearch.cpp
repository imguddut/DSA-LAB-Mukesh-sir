#include <iostream>
using namespace std;

// Function for iterative linear search
int iterativeSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Function for recursive linear search
int recursiveSearch(int arr[], int size, int key) {
    if (size < 0) {
        return -1; // Base case: key not found
    }
    if (arr[size] == key) {
        return size; // Base case: key found
    }
    return recursiveSearch(arr, size - 1, key); // Recursive case
}

int main() {
    int choice;

    int arr[] = {1, 2, 3, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Choose a search method:\n";
    cout << "1. Iterative Linear Search\n";
    cout << "2. Recursive Linear Search\n";
    cin >> choice;

    cout << "Enter the number you want to search: ";
    int key;
    cin >> key;

    int result = -1;
    if (choice == 1) {
        result = iterativeSearch(arr, size, key);
        if (result != -1) {
            cout << "Number found at index " << result << " using iterative search.\n";
        } else {
            cout << "Number not found using iterative search.\n";
        }
    } else if (choice == 2) {
        result = recursiveSearch(arr, size - 1, key); // Start from the last index
        if (result != -1) {
            cout << "Number found at index " << result << " using recursive search.\n";
        } else {
            cout << "Number not found using recursive search.\n";
        }
    } else {
        cout << "Invalid choice! Please select 1 or 2.\n";
    }

    return 0;
}