#include <iostream>
#include <cmath> // For pow function
using namespace std;

// Function to calculate the value of the polynomial
void evaluatePolynomial(int coefficients[], int degree, int xValue) {
    int term = 0;       // To store the value of each term
    int totalSum = 0;   // To store the sum of all terms

    cout << "Polynomial evaluation:\n";
    for (int i = 0; i <= degree; i++) {
        if (i == 0) {
            term = coefficients[0];
            cout << term;
        } else {
            term = coefficients[i] * pow(xValue, i);
            cout << " + " << term;
        }
        totalSum += term;
    }
    cout << " = " << totalSum << endl;
}

int main() {
    // Define the polynomial coefficients
    int coefficients[] = {1, 3, 5, 7}; // Coefficients for f(x) = 1 + 3x + 5x^2 + 7x^3
    int degree = sizeof(coefficients) / sizeof(coefficients[0]) - 1; // Degree of the polynomial

    // Define the value of x for evaluation
    int xValue = 2;

    // Call the function
    evaluatePolynomial(coefficients, degree, xValue);

    return 0;
}