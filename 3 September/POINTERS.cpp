#include <iostream>
using namespace std;

int main() {
    int number = 100; // Renamed v to number for clarity
    int *numPtr;      // Renamed ptr to numPtr for clarity
    int **doublePtr;  // Renamed p to doublePtr for clarity

    // Storing the address of number in numPtr
    numPtr = &number;

    // Storing the address of numPtr in doublePtr
    doublePtr = &numPtr;

    // Output the value of the variable 'number'
    cout << "Value of number: " << number << endl;
    cout << "Value of *numPtr: " << *numPtr << endl;  // Dereferencing numPtr to get the value
    cout << "Value of **doublePtr: " << **doublePtr << endl; // Dereferencing doublePtr twice

    // Output the address of 'number'
    cout << "Value of numPtr (address of number): " << numPtr << endl;
    cout << "Address of number: " << &number << endl;

    // Output the address stored in doublePtr (which is the address of numPtr)
    cout << "Value of *doublePtr (address of numPtr): " << *doublePtr << endl;

    // Output the address of numPtr
    cout << "Value of doublePtr (address of numPtr): " << doublePtr << endl;
    cout << "Address of numPtr: " << &numPtr << endl;

    return 0;
}
