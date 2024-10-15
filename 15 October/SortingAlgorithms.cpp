#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
}

// Heap sort function
void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Heapify the reduced heap
    }
}

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        // Find the minimum element in the unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(arr[minIdx], arr[i]);
    }
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Partition function for quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {45, 12, 23, 67, 34, 89, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    // Heap Sort
    heapSort(arr, n);
    cout << "\nArray after Heap Sort:\n";
    printArray(arr, n);

    // Reset array for other sorting algorithms
    int arr2[] = {45, 12, 23, 67, 34, 89, 10};

    // Insertion Sort
    insertionSort(arr2, n);
    cout << "\nArray after Insertion Sort:\n";
    printArray(arr2, n);

    // Reset array for other sorting algorithms
    int arr3[] = {45, 12, 23, 67, 34, 89, 10};

    // Selection Sort
    selectionSort(arr3, n);
    cout << "\nArray after Selection Sort:\n";
    printArray(arr3, n);

    // Reset array for other sorting algorithms
    int arr4[] = {45, 12, 23, 67, 34, 89, 10};

    // Bubble Sort
    bubbleSort(arr4, n);
    cout << "\nArray after Bubble Sort:\n";
    printArray(arr4, n);

    // Reset array for quick sort
    int arr5[] = {45, 12, 23, 67, 34, 89, 10};

    // Quick Sort
    quickSort(arr5, 0, n - 1);
    cout << "\nArray after Quick Sort:\n";
    printArray(arr5, n);

    return 0;
}