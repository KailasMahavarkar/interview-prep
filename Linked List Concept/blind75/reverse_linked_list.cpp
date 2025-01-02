#include <bits/stdc++.h>
using namespace std;

class ListNode {
   public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
    ListNode* ll = head;

    while (ll != nullptr) {
        cout << ll->val << " ";
        ll = ll->next;
    }
    cout << endl;
}

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head;
        ListNode* backward = nullptr;
        ListNode* forward = nullptr;

        while (curr != nullptr) {
            forward = curr->next;
            curr->next = backward;
            backward = curr;
            curr = forward;
        }

        // when while loop ends
        // where do you think curr, backward and forward will be at?
        // curr = forward = out of bound
        // backward will be pointing at curr (before curr was modified)
        // also
        // in while condition we check if curr != nullptr
        // no curr will always be nullptr
        return backward;
    }
};

