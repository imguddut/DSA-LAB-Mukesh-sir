#include<iostream>
#include<stack>
using namespace std;

// Function to reverse a stack
void reverseStack(stack<int>& st) {
    // Base case: if the stack is empty, return
    if (st.empty()) {
        return;
    }

    // Pop the top element and hold it in a variable
    int topElement = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);

    // Push the top element back into the stack (after the recursion)
    st.push(topElement);
}

int main() {
    stack<int> numberStack;

    // Adding some values to the stack
    numberStack.push(10);
    numberStack.push(20);
    numberStack.push(30);
    numberStack.push(40);
    numberStack.push(50);

    // Display the size of the stack before reversing
    cout << "Stack size before reversing: " << numberStack.size() << endl;

    // Reverse the stack using the reverseStack function
    reverseStack(numberStack);

    // Display the size of the stack after reversing
    cout << "Stack size after reversing: " << numberStack.size() << endl;

    // Display the reversed stack
    cout << "Reversed stack elements: ";
    while (!numberStack.empty()) {
        cout << numberStack.top() << " ";
        numberStack.pop();
    }
    cout << endl;

    return 0;
}
