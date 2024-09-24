#include <iostream>
using namespace std;

#define MAX_SIZE 10

// Stack structure to hold the stack elements and top pointer
struct StackOperations {
    int top;
    int arr[MAX_SIZE];

    // Constructor to initialize the stack
    StackOperations() {
        top = -1; // Stack is initially empty
    }

    // Member functions to perform operations on the stack
    bool addToStack(int x);
    int removeFromStack();
    void getTop();
    bool isStackEmpty();
};

// Function to push an element onto the stack
bool StackOperations::addToStack(int x) {
    if (top >= (MAX_SIZE - 1)) {
        cout << "Stack Overflow" << endl;
        return false;
    } else {
        arr[++top] = x;
        cout << "Pushed " << x << " to stack" << endl;
        return true;
    }
}

// Function to pop an element from the stack
int StackOperations::removeFromStack() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return -1;
    } else {
        cout << "Popped " << arr[top] << " from stack" << endl;
        return arr[top--];
    }
}

// Function to peek at the top element of the stack
void StackOperations::getTop() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element is: " << arr[top] << endl;
    }
}

// Function to check if the stack is empty
bool StackOperations::isStackEmpty() {
    return top == -1;
}

int main() {
    StackOperations stackInstance;

    // Push some elements to the stack
    stackInstance.addToStack(10);
    stackInstance.addToStack(20);
    stackInstance.addToStack(30);

    // Peek at the top element
    stackInstance.getTop();

    // Pop an element from the stack
    stackInstance.removeFromStack();

    // Peek again after popping
    stackInstance.getTop();

    // Check if the stack is empty
    if (stackInstance.isStackEmpty()) {
        cout << "The stack is now empty." << endl;
    } else {
        cout << "The stack is not empty." << endl;
    }

    return 0;
}