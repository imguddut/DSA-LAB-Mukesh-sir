#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

// Function to display the elements
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

// Function to sort the array
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    displayArray(arr, size);
}

// Function to search an element (Binary Search)
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1; // Element not found
}

// Function to insert an element at a specific index
void insertElement(int arr[], int &size, int value, int index) {
    if (index < 0 || index > size) {
        cout << "Invalid index!" << endl;
        return;
    }
    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
    displayArray(arr, size);
    sortArray(arr, size);  // Sorting after insertion
}

// Function to delete an element by value
void deleteElement(int arr[], int &size, int value) {
    int index = binarySearch(arr, size, value);
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        sortArray(arr, size); // Sorting after deletion
    } else {
        cout << "Value not found!" << endl;
    }
}

// Function to update an element at a given position
void updateElement(int arr[], int size, int position, int newValue) {
    if (position >= 0 && position < size) {
        arr[position] = newValue;
        sortArray(arr, size); // Sorting after update
    } else {
        cout << "Invalid position!" << endl;
    }
}

// Function to clear all elements in the array
void clearArray(int arr[], int size) {
    fill(arr, arr + size, 0);
    displayArray(arr, size);
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int totalSize = rows * cols;
    int array[rows][cols];
    int arr[totalSize];
    int k = 0;

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> array[i][j];
            arr[k++] = array[i][j];  // Flattening the 2D array into 1D
        }
    }

    int size = totalSize;
    char continueChoice;

    do {
        int operationChoice;
        cout << "\nChoose an operation:\n";
        cout << "1. Search\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Clear\n";
        cout << "5. Sort\n";
        cout << "6. Display\n";
        cout << "7. Update\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> operationChoice;

        switch (operationChoice) {
        case 1: {
            int key;
            cout << "Enter the key to search: ";
            cin >> key;
            int result = binarySearch(arr, size, key);
            if (result != -1) {
                cout << "Element found at index " << result << endl;
            } else {
                cout << "Element not found." << endl;
            }
            break;
        }
        case 2: {
            int value, index;
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the index to insert the value: ";
            cin >> index;
            insertElement(arr, size, value, index);
            break;
        }
        case 3: {
            int value;
            cout << "Enter the value to delete: ";
            cin >> value;
            deleteElement(arr, size, value);
            break;
        }
        case 4: {
            clearArray(arr, size);
            break;
        }
        case 5: {
            sortArray(arr, size);
            break;
        }
        case 6: {
            cout << "Displaying the array: ";
            displayArray(arr, size);
            break;
        }
        case 7: {
            int position, newValue;
            cout << "Enter the position to update: ";
            cin >> position;
            cout << "Enter the new value: ";
            cin >> newValue;
            updateElement(arr, size, position, newValue);
            break;
        }
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

        if (operationChoice != 8) {
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> continueChoice;
        }
    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}