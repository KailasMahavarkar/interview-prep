#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* vectorToLL(vector<int> arr) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    for (int i = 0; i < arr.size(); i++) {
        ListNode* node = new ListNode(arr[i]);
        if (head == nullptr) {
            head = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }
    return head;
}

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // head = A
        // head->next = B
        // head->next->next = C

        // store previous value of head->next
        ListNode* temp = head->next;

        // A->next = swapPairs(C)
        head->next = swapPairs(head->next->next);

        // B->next = A
        (temp)->next = head;

        // temp is new head now
        return temp;
    }
};

int main() {
    vector<int> nodes = {1, 2, 3, 4};
    Solution sol;
    ListNode* answer = sol.swapPairs(vectorToLL(nodes));

    while (answer != nullptr) {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout << endl;
}
