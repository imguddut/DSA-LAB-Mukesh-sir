#include<iostream>
using namespace std;

// Global variable to count the moves
static int moveCount = 0;

// Function to solve Tower of Hanoi problem
void solveTOH(int n, char fromPeg, char auxPeg, char toPeg) {
    if (n == 1) {
        moveCount++;
        return;
    } else {
        solveTOH(n - 1, fromPeg, toPeg, auxPeg);  // Move n-1 disks from 'from' to 'aux'
        solveTOH(n - 1, auxPeg, fromPeg, toPeg);  // Move n-1 disks from 'aux' to 'to'
    }
}

int main() {
    int moveCounts[19];
    int diskCounts[19];

    int k = 0, l = 0;

    // Calculate the moves for different disk counts (from 2 to 19)
    for (int disks = 2; disks < 20; disks++) {
        moveCount = 0;
        solveTOH(disks, 'A', 'B', 'C');  // Solve for n disks
        cout << "Total moves required for n = " << disks << " disks: " << moveCount << endl;

        moveCounts[k++] = moveCount;
        diskCounts[l++] = disks;
    }

    // Output the move counts and corresponding disk counts
    cout << "\nMove counts for each disk count: ";
    for (int i = 0; i < 19; i++) {
        cout << moveCounts[i] << ", ";
    }
    cout << endl;

    cout << "Disk counts: ";
    for (int i = 0; i < 19; i++) {
        cout << diskCounts[i] << ", ";
    }
    cout << endl;

    return 0;
}