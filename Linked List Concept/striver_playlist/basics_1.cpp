#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;

    ListNode(int x) {
        data = x;
        next = nullptr;
    }
};

ListNode* vectorToLinkedList(vector<int> arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        mover->next = new ListNode(arr[i]);
        mover = mover->next;
    }

    return head;
}

int main() {
    vector<int> arr = {3, 1, 2, 0};
    ListNode* head = vectorToLinkedList(arr);

    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}