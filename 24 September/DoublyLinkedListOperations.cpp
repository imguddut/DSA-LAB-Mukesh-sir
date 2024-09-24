#include <iostream>
using namespace std;

// Define the Node structure for the doubly linked list
struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int d) {
        this->data = d;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Function to traverse the doubly linked list and display its elements
void traverseList(Node *head) {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->data << " <=> ";
        currentNode = currentNode->next;
    }
    cout << "nullptr" << endl;
}

// Function to search for a value in the doubly linked list
void searchNode(Node *head, int target) {
    Node *currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->data == target) {
            cout << target << " is present in the list." << endl;
            return;
        }
        currentNode = currentNode->next;
    }
    cout << target << " is not present in the list." << endl;
}

// Function to find the length of the doubly linked list
int getListLength(Node *head) {
    Node *currentNode = head;
    int length = 0;
    while (currentNode != nullptr) {
        length++;
        currentNode = currentNode->next;
    }
    return length;
}

// Function to insert a node at the beginning of the list
Node* insertAtBeginning(Node *head, int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    return newNode;
}

// Function to insert a node at the end of the list
Node* insertAtEnd(Node *head, int value) {
    Node *newNode = new Node(value);
    if (head == nullptr) {
        return newNode;
    }
    Node *currentNode = head;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    newNode->prev = currentNode;
    return head;
}

// Function to insert a node at any given position in the list
Node* insertAtPosition(Node *head, int position, int value) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return head;
    }
    Node *newNode = new Node(value);
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        return newNode;
    }
    Node *currentNode = head;
    for (int i = 1; currentNode != nullptr && i < position - 1; i++) {
        currentNode = currentNode->next;
    }
    if (currentNode == nullptr) {
        cout << "Position out of bounds!" << endl;
        return head;
    }
    newNode->next = currentNode->next;
    if (currentNode->next != nullptr) {
        currentNode->next->prev = newNode;
    }
    currentNode->next = newNode;
    newNode->prev = currentNode;
    return head;
}

// Function to delete the first node of the list
Node* deleteAtBeginning(Node *head) {
    if (head == nullptr) return nullptr;
    Node *nodeToDelete = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete nodeToDelete;
    return head;
}

// Function to delete the last node of the list
Node* deleteAtEnd(Node *head) {
    if (head == nullptr) return nullptr;
    Node *currentNode = head;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    if (currentNode->prev != nullptr) {
        currentNode->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete currentNode;
    return head;
}

// Function to delete a node at a given position in the list
Node* deleteAtPosition(Node *head, int position) {
    if (position < 1 || head == nullptr) {
        cout << "Invalid position!" << endl;
        return head;
    }
    if (position == 1) {
        return deleteAtBeginning(head);
    }
    Node *currentNode = head;
    for (int i = 1; currentNode != nullptr && i < position; i++) {
        currentNode = currentNode->next;
    }
    if (currentNode == nullptr) {
        cout << "Position out of bounds!" << endl;
        return head;
    }
    if (currentNode->next != nullptr) {
        currentNode->next->prev = currentNode->prev;
    }
    if (currentNode->prev != nullptr) {
        currentNode->prev->next = currentNode->next;
    }
    delete currentNode;
    return head;
}

int main() {
    // Creating a doubly linked list with initial values
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Original List: ";
    traverseList(head);

    searchNode(head, 30);
    cout << "List Length: " << getListLength(head) << endl;

    // Inserting at the beginning, end, and specific position
    head = insertAtBeginning(head, 40);
    cout << "After inserting 40 at the beginning: ";
    traverseList(head);

    head = insertAtEnd(head, 50);
    cout << "After inserting 50 at the end: ";
    traverseList(head);

    head = insertAtPosition(head, 3, 60);
    cout << "After inserting 60 at position 3: ";
    traverseList(head);

    // Deleting nodes at the beginning, end, and specific position
    head = deleteAtBeginning(head);
    cout << "After deleting the first node: ";
    traverseList(head);

    head = deleteAtEnd(head);
    cout << "After deleting the last node: ";
    traverseList(head);

    head = deleteAtPosition(head, 3);
    cout << "After deleting node at position 3: ";
    traverseList(head);

    return 0;
}