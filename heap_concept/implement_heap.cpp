#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
   private:
    vector<int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        int right = rightChild(i);
        if (right < heap.size() && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

   public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) {
            return -1;  // or any suitable value indicating error
        }
        int maxVal = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(0);
        return maxVal;
    }

    int peek() {
        if (heap.empty()) {
            return -1;  // or any suitable value indicating error
        }
        return heap[0];
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(30);
    maxHeap.insert(20);
    maxHeap.insert(50);

    cout << "Max Element: " << maxHeap.peek() << endl;

    cout << "Extracted Max Element: " << maxHeap.extractMax() << endl;
    cout << "Max Element after extraction: " << maxHeap.peek() << endl;

    return 0;
}
