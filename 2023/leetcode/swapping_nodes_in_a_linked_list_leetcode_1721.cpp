#include <bits/stdc++.h>
using namespace std;

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

// Explaination (translated from gpt):
// The purpose of the fast pointer is to locate the kth node from the beginning of the list.
// It starts at the head of the list and moves k - 1 steps forward.
// This places the fast pointer at the kth node.
// By doing this, we ensure that the distance between the slow and fast pointers is always k nodes.

// Once the fast pointer is at the kth node, the slow pointer starts moving from the head of the list.
// Both the slow and fast pointers move one node at a time until the fast pointer reaches the end of the list.
// This ensures that the slow pointer ends up at the (n - k)th node, where n is the total number of nodes in the list.

// By locating these two nodes, the code then swaps their values.
// The slow pointer points to the first node, and the fast pointer points to the second node.
// Swapping their values completes the swap operation.

class Solution {
   public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* node1 = nullptr;
        ListNode* node2 = nullptr;

        // Move fast pointer to the kth node
        for (int i = 0; i < k - 1; i++) {
            fast = fast->next;
        }
        // Store the first node
        node1 = fast;

        // Move fast pointer to the end while maintaining the distance of k nodes
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        // Store the second node
        node2 = slow;

        // Swap the values of the two nodes
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;

        return head;
    }
};

int main() {
    Solution sol;
    vector<int> nodes = {1, 2, 3, 4, 5};

    sol.swapNodes(vectorToLL(nodes), 2);
}