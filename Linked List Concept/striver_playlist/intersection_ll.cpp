#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode* back;

    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
        this->back = nullptr;
    }

    ListNode(int x, ListNode* backward, ListNode* forward) {
        this->val = x;
        this->back = backward;
        this->next = forward;
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

void printLL(ListNode* head) {
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* h1 = headA;
        ListNode* h2 = headB;

        while (h1 != nullptr) {
            h1->val = -1 * (h1->val);
            h1 = h1->next;
        }

        ListNode* foundNode = nullptr;
        while (h2 != nullptr) {
            if (h2->val < 0 && foundNode == nullptr) {
                foundNode = h2;
                break;
            }
            h2 = h2->next;
        }

        h1 = headA;
        while (h1 != nullptr) {
            h1->val = -1 * (h1->val);
            h1 = h1->next;
        }

        return foundNode;
    }
};

int main() {
    vector<int> vec1 = {10, 11};
    vector<int> vec2 = {20, 21, 22};
    vector<int> vec3 = {30, 31, 32};

    ListNode* A = vectorToLinkedList(vec1);
    ListNode* B = vectorToLinkedList(vec2);
    ListNode* C = vectorToLinkedList(vec3);

    ListNode* tempA = A;
    ListNode* tempB = B;

    while (tempA != nullptr && tempA->next != nullptr) {
        tempA = tempA->next;
    }

    while (tempB != nullptr && tempB->next != nullptr) {
        tempB = tempB->next;
    }

    tempA->next = C;
    tempB->next = C;

    Solution sol;
    ListNode* answer = sol.getIntersectionNode(A, B);
    printLL(answer);
}