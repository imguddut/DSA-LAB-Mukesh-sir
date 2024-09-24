#include<iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node *next;
    Node(int d) {
        this->data = d;
        this->next = nullptr;
    }
};

// Function to traverse and print the circular linked list
void traverseList(Node *head) {
    if (head == nullptr) return;
    Node *current = head;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);
    cout << "(head)\n";
}

// Function to insert a node at the beginning of the list
Node* insertAtBegin(Node *head, int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the list
Node* insertAtEnd(Node *head, int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = head;
    return head;
}

// Function to insert a node at a specific position in the list
Node* insertAtPosition(Node *head, int pos, int data) {
    if (pos < 1) {
        cout << "Invalid position!" << endl;
        return head;
    }
    Node *newNode = new Node(data);
    if (pos == 1) {
        Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        return head;
    }
    int i = 2;
    Node *current = head;
    while (i < pos && current->next != head) {
        current = current->next;
        i++;
    }
    if (current->next == head) {
        cout << "Position out of bounds!" << endl;
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the first node in the list
Node* deleteFromBegin(Node *head) {
    if (head == nullptr) return nullptr;
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    Node *nodeToDelete = head;
    head = nodeToDelete->next;
    last->next = head;
    delete nodeToDelete;
    return head;
}

// Function to delete the last node in the list
Node* deleteFromEnd(Node *head) {
    if (head == nullptr || head->next == head) return nullptr;
    Node *current = head;
    while (current->next->next != head) {
        current = current->next;
    }
    delete(current->next);
    current->next = head;
    return head;
}

// Function to delete a node at a specific position in the list
Node* deleteFromPosition(Node *head, int pos) {
    if (pos < 1 || head == nullptr) return head;
    if (pos == 1) {
        return deleteFromBegin(head);
    }
    int i = 2;
    Node *current = head;
    while (i != pos && current->next != head) {
        current = current->next;
        i++;
    }
    if (current->next == head) {
        cout << "Position out of bounds!" << endl;
        return head;
    }
    Node *nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;
    return head;
}

int main() {
    // Creating a circular linked list with initial elements
    Node *head = new Node(100);
    head->next = new Node(200);
    head->next->next = new Node(300);
    head->next->next->next = head;

    // Traversing the list
    cout << "Initial List: ";
    traverseList(head);

    // Performing insertion operations
    head = insertAtBegin(head, 50);
    cout << "After inserting 50 at the beginning: ";
    traverseList(head);

    head = insertAtEnd(head, 400);
    cout << "After inserting 400 at the end: ";
    traverseList(head);

    head = insertAtPosition(head, 3, 350);
    cout << "After inserting 350 at position 3: ";
    traverseList(head);

    // Performing deletion operations
    head = deleteFromBegin(head);
    cout << "After deleting the first node: ";
    traverseList(head);

    head = deleteFromEnd(head);
    cout << "After deleting the last node: ";
    traverseList(head);

    head = deleteFromPosition(head, 2);
    cout << "After deleting the node at position 2: ";
    traverseList(head);

    return 0;
}