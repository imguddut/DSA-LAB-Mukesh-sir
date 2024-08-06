#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to perform linear search
long long linearSearch(long long arr[], long long key, long long size) {
    for (long long i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// Function to calculate the time taken for linear search and display the results
void measureTimeTaken() {
    long long arraySize = 50; // Initial size of the array

    // Loop to test for increasing array sizes
    for (long long iteration = 0; iteration < 10; iteration++) {
        long long arr[arraySize];

        // Populate the array with random numbers
        for (long long i = 0; i < arraySize; i++) {
            arr[i] = rand();
        }

        // Record the start time
        auto startTime = high_resolution_clock::now();

        // Perform linear search 100 times to calculate average time
        for (long long i = 0; i < 100; i++) {
            linearSearch(arr, arr[arraySize - 1], arraySize); // Searching the last element
        }

        // Record the stop time
        auto stopTime = high_resolution_clock::now();

        // Calculate the average time in microseconds
        auto duration = duration_cast<microseconds>(stopTime - startTime);
        double averageTime = duration.count() / 100.0;

        // Display the results
        cerr << "Array Size: " << arraySize 
             << " | Time Taken (microseconds): " << averageTime << endl;

        // Increase the array size for the next iteration
        arraySize *= 10;
    }
}

int main() {
    measureTimeTaken(); // Measure time taken for linear search
    return 0;
}
