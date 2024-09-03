#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
public:
    int value;
    Node* next;
    
    // Constructor to initialize node with a given value
    Node(int new_value) {
        value = new_value;
        next = nullptr;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->value << "  ";  // Print the value of current node
        currentNode = currentNode->next;    // Move to the next node
    }
    cout << endl;
}

int main() {
    // Creating a linked list with values 10, 20, 30, and 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Printing the linked list
    cout << "The elements in the linked list are: ";
    printList(head);

    return 0;
}