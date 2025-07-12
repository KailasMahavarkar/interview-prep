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

ListNode* vectorToListNode(vector<int> arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

ListNode* merge(ListNode* list1, ListNode* list2) {
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


ListNode* mergeSort(ListNode* head) {
    // we either have one node or no node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // disconnect one linked list into two parts
    ListNode* rightHalf = slow->next;
    slow->next = nullptr;

    ListNode* leftHalf = mergeSort(head);
    rightHalf = mergeSort(rightHalf);

    ListNode* ans = merge(leftHalf, rightHalf);
    return ans;
}

void printLL(ListNode* head) {
    ListNode* ll = head;
    while (ll != nullptr) {
        cout << ll->val << " ";
        ll = ll->next;
    }
    cout << endl;
}

int main() {
    // vector<int> arr = {1, 2, 8, 4, 10};
    // ListNode* vecLL = vectorToListNode(arr);
    // ListNode* mergeResult = mergeSort(vecLL);
    // printLL(mergeResult);

    ListNode* ll1 = vectorToListNode({1, 2, 3});
    ListNode* ll2 = vectorToListNode({2, 3, 4});

    ListNode* ll3 = merge(ll1, ll2);
    printLL(ll3);
}