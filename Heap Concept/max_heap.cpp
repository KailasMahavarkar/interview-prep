#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   private:
    int capacity = 4;
    int size = 0;

    vector<int> items;

    Solution() {
        items.resize(capacity);
    }

    int getLeftChildIndex(int idx) { return 2 * idx + 1; }
    int getRightChildIndex(int idx) { return 2 * idx + 2; }
    int getParentIndex(int idx) { return (idx - 1) / 2; }

    bool hasLeftChild(int idx) { return getLeftChildIndex(idx) < size; }
    bool hasRightChild(int idx) { return getRightChildIndex(idx) < size; }
    bool hasParent(int idx) { return getParentIndex(idx) >= 0; }

    int leftChild(int idx) { return items[getLeftChildIndex(idx)]; }
    int rightChild(int idx) { return items[getRightChildIndex(idx)]; }
    int parent(int idx) { return items[getParentIndex(idx)]; }

    void ensureExtraCapacity() {
        if (capacity == size) {
            capacity *= 2;
            items.resize(capacity);
        }
    }

   public:
    void push(int element) {
        ensureExtraCapacity();
        items[size] = element;
        size++;
        heapifyUp();
    }

    int top() {
        if (size == 0) return -1;
        return items[0];
    }

    int pop() {
        if (size == 0) return -1;
        int popTop = items[0];
        items[0] = items[size - 1];
        size--;
        heapifyDown();
        return popTop;
    }

    void heapifyUp() {
        int currentIdx = size - 1;
        while (hasParent(currentIdx) && items[currentIdx] > parent(currentIdx)) {
            swap(items[currentIdx], items[getParentIndex(currentIdx)]);
            currentIdx = getParentIndex(currentIdx);
        }
    }

    void heapifyDown() {
        int currentIdx = 0;
        while (hasLeftChild(currentIdx)) {
            int smallerChildIdx = getLeftChildIndex(currentIdx);
            if (hasRightChild(currentIdx) && rightChild(currentIdx) > leftChild(currentIdx)) {
                smallerChildIdx = getRightChildIndex(currentIdx);
            }
            if (items[currentIdx] >= items[smallerChildIdx]) break;
            swap(items[currentIdx], items[smallerChildIdx]);
            currentIdx = smallerChildIdx;
        }
    }
};

int main() {
    Solution heap;

    heap.push(10);
    heap.push(20);
    heap.push(30);
    heap.push(40);
    heap.push(5);

    heap.pop();
    heap.pop();

    cout << "Top value: " << heap.top() << endl;

    return 0;
}
