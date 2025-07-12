#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> s;

        while (head != NULL) {
            if (s.count(head) > 0) {
                return true;
            }

            s.insert(head);
            head = head->next;
        }

        return false;
    }
};

int main() {
    cout << "hello" << endl;

    vector<int> arr = {1};
    ListNode *ll = vectorToListNodeCycle(arr, -1);

    Solution sol;
    bool answer = sol.hasCycle(ll);

    cout << "cycle is " << answer << endl;
}