#include <iostream>
using namespace std;

// Recursive function to calculate the sum of array elements
void calculateSum(int numbers[], int totalSum, int index) {
    if (index < 7) { // Process only until the array's last valid index
        totalSum += numbers[index];
        index++;
        calculateSum(numbers, totalSum, index);
    } else {
        cout << "The total sum of the numbers is: " << totalSum << endl;
    }
}

int main() {
    int numbers[7] = {3, 5, 8, 10, 12, 15, 20}; // Changed array size and elements
    int totalSum = 0, index = 0;

    calculateSum(numbers, totalSum, index); // Start the recursive calculation

    return 0;
}