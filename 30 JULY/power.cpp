//                                     Algorithm:
// Initialize result as 1 to store the intermediate product.
// Loop: Iterate from 1 to exponent / 2.
// In each iteration, multiply result by the base.
// Check the parity of exponent:
// If exponent is even, the final answer is result * result.
// If exponent is odd, the final answer is result * result * base.
// Output the calculated result.


#include <iostream>
using namespace std;

void powerCalculation(int base, int exponent)
{
    int result = 1;
    for (int i = 1; i <= exponent / 2; i++)
    {
        result *= base;
    }
    if (exponent % 2 == 0)
    {
        cout << "The value of " << base << "^" << exponent << " is: " << result * result;
    }
    else
    {
        cout << "The value of " << base << "^" << exponent << " is: " << result * result * base;
    }
}

int main()
{
    int base, exponent;
    cout << "Enter the base number: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;
    powerCalculation(base, exponent);
}
