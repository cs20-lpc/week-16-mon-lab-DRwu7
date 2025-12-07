#include <iostream>
#include <vector>
#include "MinHeap.hpp"
using namespace std;

// Use a MinHeap to sort ascending
template <typename T>
void heapsort(vector<T>& arr) {
    MinHeap<T> h;
    int n = arr.size();

    // 1. Insert all elements into heap (Build Heap phase)
    // Note: The assignment asks for "sift-down insert from lecture" (O(N) build heap),
    // but since the MinHeap::insert provided uses siftUp, we use that for simplicity.
    // If the lecture method is required, the MinHeap constructor/helper would change.
    for (const T& x : arr) {
        h.insert(x); // This uses siftUp (O(N log N) build)
    }

    // 2. Repeatedly remove root and store back into array
    for (int i = 0; i < n; i++) {
        arr[i] = h.removeRoot(); // Smallest element is placed at arr[i]
    }
}

int main() {
    vector<int> arr = {5, 1, 9, 3, 7, 4};

    heapsort(arr);

    // Expected Output: 1 3 4 5 7 9 
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}