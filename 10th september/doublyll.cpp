#include <iostream>
using namespace std;

// Structure for Doubly Linked List Node
struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        data = d;
        next = prev = nullptr;
    }
};

// Function to traverse the list forward (from head to tail)
void traverseForward(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to traverse the list backward (from tail to head)
void traverseBackward(Node *tail)
{
    Node *temp = tail;
    while (temp != nullptr)
    {
        cout << temp->data << "  ";
        temp = temp->prev;
    }
    cout << endl;
}

// Function to find the length of the doubly linked list
int getListLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to insert a new node at the beginning of the list
Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    if (head != nullptr)
    {
        head->prev = newNode;
    }
    return newNode; // New head of the list
}

// Function to insert a new node at the end of the list
Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        return newNode; // If the list is empty, new node becomes head
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to insert a new node at a specific position
Node *insertAtPosition(Node *head, int position, int data)
{
    if (position <= 0)
    {
        cout << "Invalid position! Inserting at the beginning instead.\n";
        return insertAtBeginning(head, data);
    }

    Node *newNode = new Node(data);
    Node *temp = head;

    for (int i = 1; temp != nullptr && i < position; ++i)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position out of bounds! Inserting at the end.\n";
        return insertAtEnd(head, data);
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    return head;
}

int main()
{
    // Creating initial nodes
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Linking nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Traverse the list after initial creation
    cout << "Initial list (forward): ";
    traverseForward(head);

    // Insert at the beginning
    head = insertAtBeginning(head, 5);
    cout << "After inserting at the beginning: ";
    traverseForward(head);

    // Insert at the end
    head = insertAtEnd(head, 60);
    cout << "After inserting at the end: ";
    traverseForward(head);

    // Insert at a specific position (position 3)
    head = insertAtPosition(head, 3, 25);
    cout << "After inserting at position 3: ";
    traverseForward(head);

    // Find and print the length of the list
    int length = getListLength(head);
    cout << "Length of the list: " << length << endl;

    // Traverse the list backward (from tail to head)
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    cout << "List in reverse (backward): ";
    traverseBackward(tail);

    return 0;
}