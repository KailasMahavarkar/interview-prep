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

ListNode* vectorToListNode(vector<int>& arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

/*
    Problem Link   : https://leetcode.com/problems/remove-nodes-from-linked-list/description
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (monotonic stack + forward iteration)
// TC : O(n)
// SC : O(n)
class Solution {
   public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        ListNode* ans = (new ListNode());

        while (temp) {
            while (!st.empty() && temp->val > st.top()->val) {
                st.pop();
            }
            st.push(temp);
            temp = temp->next;
        }

        ListNode* curr = nullptr;
        ListNode* nxt = nullptr;
        while (!st.empty()) {
            curr = st.top();
            st.pop();
            curr->next = nxt;
            nxt = curr;
        }

        return curr;
    }
};

int main() {
    vector<int> nodes = {5, 2, 13, 3, 8};
    Solution sol;
    ListNode* myhead = vectorToListNode(nodes);
    ListNode* ans = sol.removeNodes(myhead);
    printLL(ans);
}