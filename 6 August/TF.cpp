#include <iostream>
using namespace std;

// Recursive function to generate and print the pattern
void generatePattern(int position, int n, char pattern[]) {
    if (position == n) {
        for (int i = 0; i < n; i++) {
            cout << pattern[i];
        }
        cout << " ";
    } else {
        pattern[position] = 'F';
        generatePattern(position + 1, n, pattern);
        pattern[position] = 'T';
        generatePattern(position + 1, n, pattern);
    }
}

int main() {
    int n;
    cout << "Enter the value of n (number of characters in each combination): ";
    cin >> n;

    char pattern[n];
    cout << "Generated pattern:\n";
    generatePattern(0, n, pattern);
    cout << endl;

    return 0;
}