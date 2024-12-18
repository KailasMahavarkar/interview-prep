#include <bits/stdc++.h>
using namespace std;

class MinHeap {
   public:
    int size = 0;
    int capacity = 10;
    vector<int> heap;

    MinHeap() {
        heap.resize(capacity);
    }

    int getLeftIndex(int idx) { return 2 * idx + 1; };
    int getRightIndex(int idx) { return 2 * idx + 1; };
    int getParentIndex(int idx) { return (idx - 1) / 2; };

    int hasLeftChild(int idx) { return getLeftIndex(idx) < size; };
    int hasRightChild(int idx) { return getRightIndex(idx) < size; };
    int hasParent(int idx) { return getParentIndex(idx) >= 0; };

    int leftChild(int idx) { return heap[getLeftIndex(idx)]; };
    int rightChild(int idx) { return heap[getRightIndex(idx)]; };
    int parent(int idx) { return heap[getParentIndex(idx)]; };

    void ensureCapacity() {
        if (capacity == size) {
            capacity = capacity * 2;
            heap.resize(capacity);
        }
    }

    int top() {
        if (size == 0) return -1;
        return heap[0];
    }

    void push(int element) {
        // check and ensure we have extra size to push new item
        ensureCapacity();

        // add new item to end of tree
        heap[size] = element;

        // increment size
        size++;

        // re-adjust heap -> heapify up
        heapifyUp();
    }

    int pop() {
        // cannot pop if no element exists
        if (size == 0) return -1;

        int popElement = heap[0];

        // swap end element and top
        swap(heap[0], heap[size - 1]);

        // remove heap[0] -> which is at bottom
        size--;

        // readjust heap from top
        heapifyDown();
    }

    void heapifyUp() {
        int idx = size - 1;

        //  7
        // 2   3
        // 4 5 6 1

        while (hasParent(idx) && heap[idx] < heap[getParentIndex(idx)]) {
            swap(heap[idx], heap[getParentIndex(idx)]);
            idx = heap[getParentIndex(idx)];
        }
    }

    void heapifyDown() {
        int idx = 0;

        while (hasLeftChild(idx)) {
            // lets make assumption leftChild is smaller
            int smallerIndex = getLeftIndex(idx);

            // validate the assumption if left is still smaller
            if (hasRightChild(idx) && rightChild(idx) < leftChild(idx)) {
                smallerIndex = getRightIndex(idx);
            }

            //           1 <- idx
            //  si->   2    3
            //        4 5  6 7

            if (items[idx] <= items[smallerIndex]) break;
            swap(heap[smallerIndex], idx);
            idx = smallerIndex;
        }
    }
};

int main() {
    MinHeap hp;
    hp.push(10);
    hp.push(20);
    hp.push(30);

    cout << "top --> " << hp.top() << endl;
}