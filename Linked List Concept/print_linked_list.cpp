#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* vectorToListNode(vector<int>& arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

/*
    Problem Link   : https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    ListNode* printLL(ListNode* head) {
        while (head != NULL) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    vector<int> nodes = {2, 0, 8048};
    Solution sol;
    ListNode* myhead = vectorToListNode(nodes);
    ListNode* ans = sol.doubleIt(myhead);
    printLL(ans);
}