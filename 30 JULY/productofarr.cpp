//                                         Algorithm
// Input: Take the size n of array A and its elements as input from the user. Ensure that no input is 0.
// Initialize Product: Set an integer variable product to 1.
// Compute Total Product: Iterate through all elements of array A and multiply each element to product.
// Create Result Array B:
// For each element in A, calculate B[i] as product / A[i] and store it in the array B.
// Output Result: Print each element of array B.
// End


#include <iostream>
using namespace std;

void inputArray(int n, int arrA[])
{
    cout << "Enter elements for the first array (Avoid using '0'):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arrA[i];
    }
}

void calculateProductArray(int n, int arrA[], int arrB[])
{
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        product *= arrA[i];
    }
    for (int i = 0; i < n; i++)
    {
        arrB[i] = product / arrA[i];
    }
    
    cout << "Resultant Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arrB[i] << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the first array: ";
    cin >> n;
    cout << "\n";
    int arrA[n], arrB[n];
    inputArray(n, arrA);
    calculateProductArray(n, arrA, arrB);
    return 0;
}