#include <iostream>
using namespace std;

// Function to accept n elements from the user into an array
void getInput(int n, int arr[]) 
{
    cout << "Please enter the elements:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "You entered the following elements:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

// Function to sort the array in ascending order
void sortArray(int n, int arr[]) 
{
    int temp;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[i] > arr[j]) 
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

// Main function to process input and find triplets where a + b = c
int main() 
{
    int n;
    cout << "Enter the number of elements you want to input: ";
    cin >> n;
    
    int arr[n];
    getInput(n, arr);
    sortArray(n, arr);

    cout << "The triplets (a, b, c) where a + b = c are:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            for (int k = 0; k < n; k++) 
            {
                if (arr[i] + arr[j] == arr[k]) 
                {
                    cout << "(" << arr[i] << ", " << arr[j] << ", " << arr[k] << ")\n";
                }
            }
        }
    }

    return 0;
}
