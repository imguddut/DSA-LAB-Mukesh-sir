#include<iostream>
#include<queue>
using namespace std;

// Define the Node structure
struct Node {
    int value;
    Node* next;
    Node(int val) {
        this->value = val;
        this->next = nullptr;
    }
};

// Function to insert a node at the end of the list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to traverse and print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find the maximum value in the linked list
int findMax(Node* head) {
    int maxVal = head->value;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->value > maxVal) {
            maxVal = temp->value;
        }
        temp = temp->next;
    }
    return maxVal;
}

// Function to get the digit at the given place (units, tens, hundreds, etc.)
int getDigit(int num, int place) {
    return (num / place) % 10;
}

// Function to perform counting sort based on the current digit place
Node* countingSort(Node* head, int place) {
    // Create 10 buckets (queues) for digits 0-9
    queue<Node*> buckets[10];

    // Distribute nodes into buckets based on the digit at the current place
    Node* temp = head;
    while (temp != nullptr) {
        int digit = getDigit(temp->value, place);
        buckets[digit].push(temp);
        temp = temp->next;
    }

    // Collect nodes back from the buckets and reform the list
    Node* newHead = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 10; ++i) {
        while (!buckets[i].empty()) {
            Node* node = buckets[i].front();
            buckets[i].pop();
            node->next = nullptr;  // Disconnect the node from its next pointer
            if (newHead == nullptr) {
                newHead = node;
                tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
        }
    }
    return newHead;
}

// Function to perform Radix Sort on the linked list
Node* radixSort(Node* head) {
    // Find the maximum number to determine the number of digits
    int maxVal = findMax(head);

    // Perform counting sort for each digit place (units, tens, hundreds, etc.)
    for (int place = 1; maxVal / place > 0; place *= 10) {
        head = countingSort(head, place);
    }
    return head;
}

int main() {
    // Create an unsorted linked list with random values
    Node* head = nullptr;
    head = insertAtEnd(head, 315);
    head = insertAtEnd(head, 45);
    head = insertAtEnd(head, 123);
    head = insertAtEnd(head, 802);
    head = insertAtEnd(head, 51);
    head = insertAtEnd(head, 935);
    head = insertAtEnd(head, 70);
    head = insertAtEnd(head, 56);

    // Print the unsorted linked list
    cout << "Unsorted Linked List: ";
    printList(head);

    // Perform Radix Sort
    head = radixSort(head);

    // Print the sorted linked list
    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
