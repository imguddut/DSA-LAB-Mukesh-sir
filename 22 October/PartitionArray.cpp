#include <iostream>
#include <algorithm>
using namespace std;

// Function to partition the array
void partitionArray(int array[], int size) {
    int pivot = array[0]; // Choose the first element as the pivot
    int left = 0;
    int right = size - 1;

    while (left < right) {
        // Find the first element greater than or equal to the pivot from the left
        while (left < right && array[left] <= pivot) {
            left++;
        }

        // Find the first element smaller than or equal to the pivot from the right
        while (array[right] > pivot) {
            right--;
        }

        // Swap elements if left is less than right
        if (left < right) {
            swap(array[left], array[right]);
        }
    }

    // Place the pivot in its correct position
    swap(array[0], array[right]);
}

int main() {
    // Input array
    int array[] = {15, 3, 12, 6, 10, 7};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Perform partitioning
    partitionArray(array, size);

    // Output the partitioned array
    cout << "Array after partitioning (pivot correctly placed): ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}