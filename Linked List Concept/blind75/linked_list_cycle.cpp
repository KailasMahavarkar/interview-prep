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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* start = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            if (slow == fast){
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};

int main() {
    Solution sol;
    bool isCyclePresent = sol.hasCycle(vectorToLinkedList({3, 2, 0, -4}));
    cout << isCyclePresent << boolalpha << endl;
}