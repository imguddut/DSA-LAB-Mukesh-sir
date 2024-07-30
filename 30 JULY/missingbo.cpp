                            //  Algorithm Explanation
// Input Reading:

// Get the starting number of the sequence.
// Get the total count of numbers in the sequence (including the missing one).
// Take input for the sequence, excluding the missing number.
// Expected XOR Calculation:

// Use XOR to compute the cumulative XOR of all numbers from start to start + n - 1.
// Actual XOR Calculation:

// Use XOR to compute the cumulative XOR of all numbers in the array (with one missing number).
// Missing Number Identification:

// XOR the results of the expected and actual XORs. The result is the missing number, as XORing identical values cancels them out, leaving only the missing one.
// Output:

// Print the missing number.
#include <iostream>
using namespace std;

int findMissingNumber(int start, int n, int arr[]) {
    int expectedXOR = 0;
    int actualXOR = 0;

    // Calculate XOR for all numbers from start to start + n - 1
    for (int i = start; i < start + n; i++) {
        expectedXOR ^= i;
    }

    // Calculate XOR for all numbers present in the array
    for (int i = 0; i < n - 1; i++) {
        actualXOR ^= arr[i];
    }

    // The missing number is the XOR of the two results
    return expectedXOR ^ actualXOR;
}

int main() {
    int start, n;
    cout << "Enter the first number in the sequence: ";
    cin >> start;
    cout << "Enter the count of numbers in the complete sequence (including the missing one): ";
    cin >> n;

    int arr[n - 1];
    cout << "Enter the " << n - 1 << " numbers in the sequence (one is missing):\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int missingNumber = findMissingNumber(start, n, arr);
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}