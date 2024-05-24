#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/subsets/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

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

ListNode* vectorToDLL(vector<int>& arr) {
    if (arr.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        // create a new node that is floating in space -> call it temp
        ListNode* temp = new ListNode(arr[i]);

        // connect that mid's back to prev
        // [prev which is head]-----[temp]-----[next which is nullptr]
        temp->back = prev;

        // now this new prev will be current temp
        // so we move pointer of prev->next to temp (our new previous)
        prev->next = temp;

        prev = prev->next;
    }

    return head;
}

void printDLL(ListNode* head) {
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
    vector<pair<int, int>> findPairs(ListNode* head, int k) {
        ListNode* right = head;
        ListNode* left = head;
        vector<pair<int, int>> answer;

        while (right->next != nullptr) {
            right = right->next;
        }

        while (left->val < right->val) {
            if (left->val + right->val == k) {
                pair<int, int> pair({left->val, right->val});
                answer.push_back(pair);
                left = left->next;

                // remove below line to handle scenario where we want duplicate values
                right = right->back;
            } else if (left->val + right->val > k) {
                right = right->back;
            } else {
                left = left->next;
            }
        }

        return answer;
    }
};

int main() {
    vector<int> arr = {1, 2, 2, 3, 4};
    ListNode* node = vectorToDLL(arr);
    Solution sol;
    vector<pair<int, int>> pairs = sol.findPairs(node, 5);
    for (auto& pair : pairs) {
        cout << pair.first << " " << pair.second << endl;
    }
    cout << endl;
}
