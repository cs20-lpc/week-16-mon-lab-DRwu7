template <typename T>
void MinHeap<T>::siftUp(int i) {
    // Base case: Stop if we reach the root or if the heap property is satisfied
    if (i > 0 && data[i] < data[parent(i)]) {
        // Swap the child with the parent
        std::swap(data[i], data[parent(i)]);
        // Recurse up the tree
        siftUp(parent(i));
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    int n = size();
    int l = left(i);
    int r = right(i);
    int smallest = i; // Assume the current node is the smallest

    // Check if the left child exists and is smaller than the current smallest
    if (l < n && data[l] < data[smallest]) {
        smallest = l;
    }

    // Check if the right child exists and is smaller than the current smallest
    if (r < n && data[r] < data[smallest]) {
        smallest = r;
    }

    // If the smallest element is not the current node, swap and continue sifting down
    if (smallest != i) {
        std::swap(data[i], data[smallest]);
        siftDown(smallest);
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // Append the new value to the end
    data.push_back(value);
    // Sift the new value up to restore the heap property
    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    if (empty()) {
        throw runtime_error("removeRoot: Heap is empty");
    }

    // Store the root value to return later
    T rootValue = data[0];

    // Move the last element to the root position
    data[0] = data.back();
    // Remove the last element
    data.pop_back();

    // Sift the new root down to restore the heap property
    if (!empty()) {
        siftDown(0);
    }

    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    // 1. Swap element with the last element
    std::swap(data[index], data.back());
    // 2. Remove the last element
    data.pop_back();

    // 3. Attempt sift-up (in case the swapped-in element is smaller than its parent)
    // The index of the swapped element is still 'index'
    siftUp(index); 

    // 4. Then attempt sift-down (in case the element is larger than its children)
    // The index of the element remains 'index' unless size is 0
    siftDown(index);
}