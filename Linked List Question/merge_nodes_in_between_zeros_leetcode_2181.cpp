#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/merge-nodes-in-between-zeros/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

ListNode *vectorToListNode(vector<int> &arr) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

ListNode *vectorToListNodeCycle(vector<int> &arr, int pos) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    ListNode *cycleStart = NULL;

    // Traverse the array and create a linked list
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;

        // If we have reached the cycle point, save the current node as the cycle start
        if (i == pos) {
            cycleStart = temp;
        }
    }

    // If a cycle start was found, link the last node to the cycle start node
    if (cycleStart != NULL) {
        temp->next = cycleStart;
    }

    return head;
}

void printLL(ListNode *head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    ListNode *mergeNodes(ListNode *head) {
    }
};
int main() {
    vector<int> arr = {0, 3, 1, 0, 4, 5, 2, 0};
    ListNode head = vectorToListNode(arr);
    Solution sol;
    ListNode *ans = sol.mergeNodes(head);
}