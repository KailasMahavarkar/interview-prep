#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        slow->next = nullptr;
        delete slow;
        return head;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    ListNode* head = vectorToLinkedList(arr);

    Solution sol;
    ListNode* ans = sol.deleteMiddle(head);
    printLL(ans);
}