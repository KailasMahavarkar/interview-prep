#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *vectorToListNode(vector<int> &arr) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

vector<int> listNodeToVector(ListNode *head) {
    vector<int> arr;
    ListNode *temp = head;
    while (temp != NULL) {
        arr.push_back(temp->val);
        temp = temp->next;
    }
    return arr;
}

void printLinkedList(ListNode *head) {
    ListNode *temp = head;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

class Solution {
   public:
    ListNode *partition(ListNode *head, int x) {
        // parition linked list such that 
        // value greater than x goes to left and more goes to right
        ListNode *left = new ListNode(0);
        ListNode *right = new ListNode(0);

        ListNode *leftHead = left;
        ListNode *rightHead = right;

        while (head != NULL) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        right->next = NULL;
        left->next = rightHead->next;
        return leftHead->next;
    }
};

int main() {
    vector<int> nums = {1, 4, 3, 2, 5, 2};
    int k = 2;
    ListNode *ll = vectorToListNode(nums);

    Solution sol;
    ListNode *ans = sol.partition(ll, k);

    printLinkedList(ans);
}