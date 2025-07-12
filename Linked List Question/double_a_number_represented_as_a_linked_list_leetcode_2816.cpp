#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
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
void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* reverseLL(ListNode*& head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* forward = nullptr;

    while (curr != nullptr) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;

        // Step1: reverse linked list
        ListNode* temp = reverseLL(head);

        // Step2: solve for carry
        while (temp) {
            int currVal = temp->val;
            int currDouble = (temp->val * 2) + carry;
            string currDoubleString = to_string(currDouble);

            cout << "carry : " << carry << endl;
            cout << "temp : " << (temp->val) << endl;
            cout << "currDouble :" << currDouble % 10 << endl;

            carry = currDoubleString[0] - '0';
            temp->val = currDouble % 10;
            temp = temp->next;
        }

        // step3: reverse again
        ListNode* ans = reverseLL(temp);
        printLL(ans);

        return ans;
    }
};

int main() {
    vector<int> nodes = {2, 0, 8};
    Solution sol;
    ListNode* myhead = vectorToListNode(nodes);
    ListNode* ans = sol.doubleIt(myhead);
    printLL(ans);
}