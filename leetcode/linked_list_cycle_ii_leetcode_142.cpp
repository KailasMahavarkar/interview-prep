#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printLL(ListNode *head) {
    ListNode *temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *vectorToLL(vector<int> &v) {
    ListNode *head = new ListNode(v[0]);
    ListNode *temp = head;
    for (int i = 1; i < v.size(); i++) {
        ListNode *node = new ListNode(v[i]);
        temp->next = node;
        temp = temp->next;
    }
    return head;
}

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        // either we detected cycle (OR) fast has reached NULL
        // slow and fast same nai h -> basically this checks fast has reached NULL or not
        // reference image --> https://i.imgur.com/TqeqpN2.png
        if (slow != fast) {
            // this means fast must be poimting at NULL
            return NULL;
        }

        while (temp != slow) {
            temp = temp->next;
            slow = slow->next;
        }
        return temp;
    }
};

int main() {
    vector<int> v = {3, 2, 0, -4};
    ListNode *ans = Solution().detectCycle(vectorToLL(v));
    printLL(ans);
}