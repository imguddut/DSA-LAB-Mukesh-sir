// Algorithm for Bubble Sort:
/*
    1. Start with an unordered array.
    2. Use nested loops to iterate over the array.
    3. Compare adjacent elements and swap them if they are out of order.
    4. Repeat this process until the array is sorted.
    5. Print the sorted array.
*/

#include <iostream>
using namespace std;

int main() {
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    int arr[arraySize];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < arraySize; i++) {
        cin >> arr[i];
    }

    // Bubble Sort Algorithm
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Output the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}