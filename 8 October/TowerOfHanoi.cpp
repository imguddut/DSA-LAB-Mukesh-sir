#include <iostream>
using namespace std;

// Function to solve Tower of Hanoi puzzle
void solveTOH(int disks, char source, char auxiliary, char target) {
    if (disks == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
    } else {
        // Move (n-1) disks from source to auxiliary using target as a temporary peg
        solveTOH(disks - 1, source, target, auxiliary);
        cout << "Move disk " << disks << " from " << source << " to " << target << endl;
        // Move (n-1) disks from auxiliary to target using source as a temporary peg
        solveTOH(disks - 1, auxiliary, source, target);
    }
}

int main() {
    int numDisks;

    cout << "Enter the number of disks: ";
    cin >> numDisks;

    // Solve the Tower of Hanoi puzzle with source as 'A', auxiliary as 'B', and target as 'C'
    solveTOH(numDisks, 'A', 'B', 'C');
    
    return 0;
}