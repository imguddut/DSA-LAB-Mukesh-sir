#include <iostream>
using namespace std;

// Recursive function to calculate the polynomial sum
void calculatePolynomial(int coefficients[], int result, int index, int x) {
    if (index >= 0) {
        result = coefficients[index] + x * result;
        calculatePolynomial(coefficients, result, index - 1, x);
    } else {
        cout << " = " << result << endl;
    }
}

int main() {
    int coefficients[10];
    cout << "Enter the number of terms in the polynomial: ";
    int numTerms;
    cin >> numTerms;

    cout << "Enter the coefficients (from a0 to an):" << endl;
    for (int i = 0; i < numTerms; i++) {
        cin >> coefficients[i];
    }

    cout << "Enter the value of x: ";
    int x;
    cin >> x;

    int result = coefficients[numTerms - 1]; // Initialize with the last term
    int index = numTerms - 2;               // Start from the second last term

    // Display the polynomial in readable format
    cout << coefficients[0];
    for (int i = 1; i < numTerms; i++) {
        cout << " + " << x << "[ " << coefficients[i];
    }
    for (int i = 1; i < numTerms; i++) {
        cout << " ]";
    }

    // Call the recursive function
    calculatePolynomial(coefficients, result, index, x);

    return 0;
}