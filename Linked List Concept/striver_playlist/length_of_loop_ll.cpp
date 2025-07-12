#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

class Node {
   public:
    int val;
    Node* next;
    Node* back;

    Node(int x) {
        this->val = x;
        this->next = nullptr;
        this->back = nullptr;
    }

    Node(int x, Node* backward, Node* forward) {
        this->val = x;
        this->back = backward;
        this->next = forward;
    }
};

Node* vectorToLinkedList(vector<int> arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }

    return head;
}

void printLL(Node* head) {
    if (head == nullptr) {
        cout << "ll is empty" << endl;
        return;
    }
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
   public:
    int findLength(Node*& slow, Node*& fast) {
        int count = 1;

        fast = fast->next;
        while (fast != slow) {
            count++;
            fast = fast->next;
        }
        return count;
    }

    int countNodesinLoop(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return 0;
        }

        Node* slow = head;
        Node* fast = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return findLength(slow, fast);
            }
        }

        return 0;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = vectorToLinkedList(arr);
    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = head->next;

    Solution sol;
    int ans = sol.countNodesinLoop(head);
    cout << "ans -> " << ans << endl;
}