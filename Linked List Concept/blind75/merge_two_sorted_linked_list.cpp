#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ll1 = list1;
        ListNode* ll2 = list2;
        ListNode* merged = new ListNode(-1);
        ListNode* mergedHead = merged;

        while (ll1 != nullptr && ll2 != nullptr) {
            if (ll1->val < ll2->val) {
                ListNode* temp = ll1;
                merged->next = ll1;
                ll1 = ll1->next;
                merged = merged->next;
            } else {
                ListNode* temp = ll2;
                merged->next = ll2;
                ll2 = ll2->next;
                merged = merged->next;
            }
        }

        while (ll1 != nullptr) {
            merged->next = ll1;
            ll1 = ll1->next;
            merged = merged->next;
        }

        while (ll2 != nullptr) {
            merged->next = ll2;
            ll2 = ll2->next;
            merged = merged->next;
        }

        mergedHead = mergedHead->next;
        return mergedHead;
    }
};

int main() {
    ListNode* list1 = vectorToLinkedList({1, 2, 4});
    ListNode* list2 = vectorToLinkedList({1, 3, 4});
    Solution sol;
    ListNode* list3 = sol.mergeTwoLists(list1, list2);
    printLL(list3);
}