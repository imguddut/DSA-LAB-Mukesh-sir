#include<iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
    Node(int v) {
        this->value = v;
        this->next = nullptr;
    }
};

// Function to traverse the circular linked list and display values
void traverseList(Node *head) {
    if (head == nullptr) return;
    Node *current = head;
    do {
        cout << current->value << "  ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

// Function to insert a new node at the beginning
Node* insertAtBeginning(Node *head, int value) {
    Node *newNode = new Node(value);
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

// Function to insert a new node at the end
Node* insertAtEnd(Node *head, int value) {
    Node *newNode = new Node(value);
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

// Function to insert a node at a specific position
Node* insertAtPosition(Node *head, int position, int value) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return head;
    }
    Node *newNode = new Node(value);
    if (position == 1) {
        Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        return head;
    }
    int count = 2;
    Node *current = head;
    while (count < position && current->next != head) {
        current = current->next;
        count++;
    }
    if (current->next == head) {
        cout << "Position out of bounds!" << endl;
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the node at the beginning
Node* deleteAtBeginning(Node *head) {
    if (head == nullptr) return nullptr;
    if (head->next == head) {
        delete head;
        return nullptr;
    }
    Node *last = head;
    while (last->next != head) {
        last = last->next;
    }
    Node *temp = head;
    head = head->next;
    last->next = head;
    delete temp;
    return head;
}

// Function to delete the node at the end
Node* deleteAtEnd(Node *head) {
    if (head == nullptr || head->next == head) return nullptr;
    Node *current = head;
    while (current->next->next != head) {
        current = current->next;
    }
    delete current->next;
    current->next = head;
    return head;
}

// Function to delete a node at a specific position
Node* deleteAtPosition(Node *head, int position) {
    if (position < 1 || head == nullptr) return head;
    if (position == 1) {
        return deleteAtBeginning(head);
    }
    int count = 2;
    Node *current = head;
    while (count < position && current->next != head) {
        current = current->next;
        count++;
    }
    if (current->next == head) {
        cout << "Position out of bounds!" << endl;
        return head;
    }
    Node *toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
    return head;
}

int main() {
    // Creating a circular linked list
    Node *head = new Node(100);
    head->next = new Node(200);
    head->next->next = new Node(300);
    head->next->next->next = head;

    // Traversing the list
    cout << "Initial List: ";
    traverseList(head);

    // Insertions
    head = insertAtBeginning(head, 50);
    cout << "After inserting 50 at the beginning: ";
    traverseList(head);

    head = insertAtEnd(head, 400);
    cout << "After inserting 400 at the end: ";
    traverseList(head);

    head = insertAtPosition(head, 3, 250);
    cout << "After inserting 250 at position 3: ";
    traverseList(head);

    // Deletions
    head = deleteAtBeginning(head);
    cout << "After deleting the beginning node: ";
    traverseList(head);

    head = deleteAtEnd(head);
    cout << "After deleting the last node: ";
    traverseList(head);

    head = deleteAtPosition(head, 2);
    cout << "After deleting node at position 2: ";
    traverseList(head);

    return 0;
}