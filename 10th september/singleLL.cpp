#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    
    // Constructor to initialize a node with data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to traverse and print the linked list
void traverseLinkedList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;  // Indicating the end of the list
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node *&head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    cout << "List after insertion at the beginning: ";
    traverseLinkedList(head);
}

// Function to insert a node at the end of the list
void insertAtEnd(Node *head, int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode; // List is empty, new node is the head
        cout << "List after insertion at the end: ";
        traverseLinkedList(head);
        return;
    }
    
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    cout << "List after insertion at the end: ";
    traverseLinkedList(head);
}

int main() {
    // Creating a linked list with initial values
    Node *head = new Node(20);
    head->next = new Node(30);
    head->next->next = new Node(40);

    cout << "Initial List: ";
    traverseLinkedList(head);

    // Inserting a node at the beginning
    insertAtBeginning(head, 10);

    // Inserting a node at the end
    insertAtEnd(head, 50);

    return 0;
}
