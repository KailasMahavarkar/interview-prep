#include <bits/stdc++.h>
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
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* last = reverseLinkedList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* begin = head;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast->next != nullptr) {
            fast = fast->next;
        }

        ListNode* tempLL = reverseLinkedList(slow->next);

        while (tempLL != nullptr) {
            if (tempLL->val != begin->val) {
                return false;
            }

            tempLL = tempLL->next;
            begin = begin->next;
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    ListNode* node = vectorToLinkedList(arr);
    bool ans = sol.isPalindrome(node);
    cout << boolalpha << "ans --> " << ans << endl;
}