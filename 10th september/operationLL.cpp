#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor to initialize the node
    Node(int data) {
        this->data = data;  // Corrected assignment
        this->next = nullptr;
    }
};

// Insertion at the beginning of the linked list
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

// Insertion at a specific position in the linked list
void insertAtPosition(Node*& head, int position, int data) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = new Node(data);

    // If insertion at the beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to the node just before the specified position
    Node* current = head;
    int count = 1; // Start at the first position
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }

    // If position is greater than the number of nodes
    if (current == nullptr) {
        cout << "Position exceeds the length of the list." << endl;
        delete newNode;  // Avoid memory leak
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Insertion at the end of the linked list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {  // If the list is empty
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements at different positions
    insertAtHead(head, 10);  // Insert 10 at the head
    insertAtHead(head, 5);   // Insert 5 at the head
    insertAtEnd(head, 20);   // Insert 20 at the end
    insertAtPosition(head, 2, 15);  // Insert 15 at position 2

    // Print the list
    cout << "Linked List: ";
    printList(head);

    return 0;
}