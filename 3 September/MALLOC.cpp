#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
    // Dynamic memory allocation using malloc for a single array
    int size, *dynamicArray;

    cout << "Enter the number of elements you want to store: ";
    cin >> size;

    // Dynamically allocating memory for 'size' number of integers
    dynamicArray = (int*)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (dynamicArray == NULL) {
        cout << "Memory allocation failed!" << endl;
        exit(0);
    } else {
        cout << "Memory allocated successfully!" << endl;

        // Reading elements into the dynamically allocated memory
        cout << "Enter " << size << " elements:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> dynamicArray[i];
        }

        // Display the elements stored in dynamically allocated memory
        cout << "The elements you entered are: ";
        for (int i = 0; i < size; i++) {
            cout << dynamicArray[i] << " ";
        }
        cout << endl;

        // Freeing the allocated memory
        free(dynamicArray);
        cout << "Memory freed successfully!" << endl;
    }

    return 0;
}