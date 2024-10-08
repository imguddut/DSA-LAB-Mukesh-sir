#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, capacity, currsize;

public:
    // Constructor to initialize the queue
    Queue(int size) {
        capacity = size;
        front = 0;
        rear = -1;
        currsize = 0;
        arr = new int[capacity];
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Function to display the elements of the queue
    void display() {
        if (currsize == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to add an element to the queue (enqueue)
    void Enqueue(int data) {
        if (currsize == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        currsize++;
    }

    // Function to remove an element from the queue (dequeue)
    void Dequeue() {
        if (currsize == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;
        currsize--;
    }

    // Function to get the front element
    int Front() {
        if (currsize == 0) {
            cout << "Queue is empty!" << endl;
            return -1;  // Indicating empty queue
        }
        return arr[front];
    }

    // Function to check if the queue is empty
    bool IsEmpty() {
        return currsize == 0;
    }

    // Function to check if the queue is full
    bool IsFull() {
        return currsize == capacity;
    }
};

int main() {
    Queue q(5);  // Create a queue with capacity of 5

    // Display initial queue state
    q.display();

    // Enqueue some elements
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.display();

    // Try enqueueing when the queue is full
    q.Enqueue(60);

    // Dequeue elements
    q.Dequeue();
    q.display();

    // Dequeue more elements
    q.Dequeue();
    q.display();

    // Show the front element
    cout << "Front element: " << q.Front() << endl;

    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.IsEmpty() ? "Yes" : "No") << endl;

    // Check if the queue is full
    cout << "Is the queue full? " << (q.IsFull() ? "Yes" : "No") << endl;

    return 0;
}