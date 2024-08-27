#include <iostream>
using namespace std;

// Function to calculate the address in row-major order
void calculateRowMajorAddress(int row, int col, int numCols) {
    int baseAddress = 100; // Base address of the array
    int elementSize = 4;   // Storage size of each element (in bytes)
    
    // Calculate the index of the element (row-major order)
    int address = baseAddress + elementSize * ((row - 1) * numCols + (col - 1));
    
    cout << "Element at row " << row << ", column " << col << endl;
    cout << "Base Address: " << baseAddress << endl;
    cout << "Address of Element: " << address << endl;
}

// Function to calculate the address in column-major order
void calculateColumnMajorAddress(int row, int col, int numRows) {
    int baseAddress = 100; // Base address of the array
    int elementSize = 4;   // Storage size of each element (in bytes)
    
    // Calculate the index of the element (column-major order)
    int address = baseAddress + elementSize * ((col - 1) * numRows + (row - 1));
    
    cout << "Element at row " << row << ", column " << col << endl;
    cout << "Base Address: " << baseAddress << endl;
    cout << "Address of Element: " << address << endl;
}

int main() {
    int rows, cols;
    
    // Get the size of the array from the user
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    
    int totalElements = rows * cols;
    int array[rows][cols];   // 2D array
    int rowMajorArray[totalElements];  // 1D array for row-major order
    int colMajorArray[totalElements]; // 1D array for column-major order
    
    cout << "Enter the elements of the array: \n";
    int index = 0;
    
    // Input elements and convert to row-major 1D array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> array[i][j];
            rowMajorArray[index] = array[i][j];
            index++;
        }
    }
    
    index = 0;
    // Convert to column-major 1D array
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            colMajorArray[index] = array[i][j];
            index++;
        }
    }
    
    int rowToSearch, colToSearch;
    cout << "Enter the row index to search for: ";
    cin >> rowToSearch;
    cout << "Enter the column index to search for: ";
    cin >> colToSearch;
    
    int chosenElement = array[rowToSearch - 1][colToSearch - 1]; // Adjust for 0-based index
    
    int choice;
    cout << "Choose the storage order:\n";
    cout << "1. Row-major order\n";
    cout << "2. Column-major order\n";
    cin >> choice;

    // Output the corresponding 1D array and memory address calculation
    if (choice == 1) {
        cout << "2D Array in Row-major order:\n";
        for (int i = 0; i < totalElements; i++) {
            cout << rowMajorArray[i] << " ";
        }
        cout << endl;

        calculateRowMajorAddress(rowToSearch, colToSearch, cols);
    } else if (choice == 2) {
        cout << "2D Array in Column-major order:\n";
        for (int i = 0; i < totalElements; i++) {
            cout << colMajorArray[i] << " ";
        }
        cout << endl;

        calculateColumnMajorAddress(rowToSearch, colToSearch, rows);
    } else {
        cout << "Invalid choice! Please select either 1 or 2.\n";
    }

    return 0;
}
