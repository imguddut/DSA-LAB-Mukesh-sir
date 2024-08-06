#include <iostream>
using namespace std;

// Function to calculate the sum of n numbers using recursion
int calculateSum(int numbers[], int size) {
    if (size != 0) {
        return numbers[size - 1] + calculateSum(numbers, size - 1); // Recursive case
    } else {
        return 0; // Base case
    }
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int totalSum = calculateSum(arr, n);
    cout << "The sum of the array elements is: " << totalSum << endl;

    return 0;
}