#include <iostream>
#include <cstdlib>
using namespace std;

// Define the Queue class
class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    // Constructor to initialize the queue
    Queue(int queueSize) {
        size = queueSize;
        arr = new int[size];
        front = rear = -1;
    }

    // Destructor to free the allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Function to enqueue an element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
        } else {
            if (front == -1) {  // If the queue is empty
                front = 0;
            }
            rear = (rear + 1) % size;  // Circular increment
            arr[rear] = value;
            cout << value << " enqueued to the queue.\n";
        }
    }

    // Function to dequeue an element
    int dequeue() {
        int removedValue = -1;
        if (isEmpty()) {
            cout << "Queue Underflow! Queue is empty.\n";
        } else {
            removedValue = arr[front];
            if (front == rear) {  // Only one element left
                front = rear = -1;  // Reset the queue
            } else {
                front = (front + 1) % size;  // Circular increment
            }
            cout << removedValue << " dequeued from the queue.\n";
        }
        return removedValue;
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << arr[rear] << endl;  // Print the rear element
    }
};

int main() {
    int queueSize;
    
    // Ask user for the size of the queue
    cout << "Enter the size of the queue: ";
    cin >> queueSize;

    // Create a queue object with the given size
    Queue q(queueSize);

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Display the queue
    q.display();

    // Dequeue some elements
    q.dequeue();
    q.dequeue();
    q.dequeue();

    // Display the queue after dequeuing
    q.display();

    return 0;
}
