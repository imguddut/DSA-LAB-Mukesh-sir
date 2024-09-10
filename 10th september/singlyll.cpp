#include<iostream>
using namespace std;

// Node structure definition
struct Node {
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        this->next = nullptr;
    }
};

// Function to traverse and print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << "  ";
        current = current->next;
    }
    cout << endl;
}

// Function to search for a target in the linked list
bool searchNode(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to get the length of the linked list
int listLength(Node* head) {
    Node* current = head;
    int length = 0;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

// Function to insert a node at the beginning
Node* insertAtHead(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end
Node* insertAtTail(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        return newNode;
    }
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node at a specific position
Node* insertAtPosition(Node* head, int position, int value) {
    if (position < 1) {
        cout << "Invalid Position" << endl;
        return head;
    }

    Node* newNode = new Node(value);
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* current = head;
    int index = 1;
    while (current != nullptr && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to delete the node at the beginning
Node* deleteFromHead(Node* head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete" << endl;
        return head;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Function to delete the node at the end
Node* deleteFromTail(Node* head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete" << endl;
        return head;
    }

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    return head;
}

// Function to delete the node at a specific position
Node* deleteFromPosition(Node* head, int position) {
    if (position < 1) {
        cout << "Invalid Position" << endl;
        return head;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    int index = 1;
    while (current != nullptr && index < position - 1) {
        current = current->next;
        index++;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Position out of bounds" << endl;
        return head;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}

int main() {
    // Creating the initial linked list
    Node* head = new Node(15);
    head->next = new Node(30);
    head->next->next = new Node(45);
    
    cout << "Original Linked List: ";
    printList(head);

    // Searching for a value in the list
    int target = 30;
    if (searchNode(head, target)) {
        cout << "Element " << target << " is present in the list." << endl;
    } else {
        cout << "Element " << target << " is not present in the list." << endl;
    }

    // Length of the linked list
    cout << "Length of the linked list = " << listLength(head) << endl;

    // Inserting a new node at the beginning
    head = insertAtHead(head, 10);
    cout << "After Inserting 10 at the head: ";
    printList(head);

    // Inserting a new node at the end
    head = insertAtTail(head, 60);
    cout << "After Inserting 60 at the tail: ";
    printList(head);

    // Inserting a new node at position 4
    head = insertAtPosition(head, 4, 50);
    cout << "After Inserting 50 at position 4: ";
    printList(head);

    // Deleting the first node
    head = deleteFromHead(head);
    cout << "After Deleting from head: ";
    printList(head);

    // Deleting the last node
    head = deleteFromTail(head);
    cout << "After Deleting from tail: ";
    printList(head);

    // Deleting the node at position 3
    head = deleteFromPosition(head, 3);
    cout << "After Deleting from position 3: ";
    printList(head);

    return 0;
}