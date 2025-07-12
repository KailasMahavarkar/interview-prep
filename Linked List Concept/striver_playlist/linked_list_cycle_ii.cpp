#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
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
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        // either we detected cycle (OR) fast has reached NULL
        // slow and fast same nai h -> basically this checks fast has reached NULL or not
        if (slow != fast) {
            // this means fast must be poimting at NULL
            return nullptr;
        }

        ListNode* temp = head;
        while (temp != slow) {
            temp = temp->next;
            slow = slow->next;
        }

        return temp;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    ListNode* head = vectorToLinkedList(arr);
    ListNode* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = head->next;

    Solution sol;
    bool ans = sol.hasCycle(head);
    cout << "ans -> " << boolalpha << ans << endl;
}