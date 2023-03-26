#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// vector to linked list
ListNode* vectorToList(vector<int> v) {
    if (v.size() == 0) {
        return NULL;
    }

    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;

    for (int i = 1; i < v.size(); i++) {
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }
    return head;
}

vector<ListNode*> multiVecToMultiLL(vector<vector<int>> v) {
    int n = v.size();
    vector<ListNode*> ans;
    for (int i = 0; i < n; i++) {
        ans.push_back(vectorToList(v[i]));
    }

    return ans;
}

void printLL(ListNode* LL) {
    ListNode* temp = LL;
    while (temp != NULL) {
        cout << (temp->val) << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printVector(vector<int> v) {
    for (auto& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// Failed Approach
// testcase: {{1, 4, 5}, {1, 3, 4}, {2, 6}}
// 1 1 2 3 4 6 4 5
// class Solution {
//    public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int k = lists.size();
//         ListNode* answer = new ListNode(-1);
//         bool run = true;
//         while (run == true) {
//             vector<int> temp;

//             for (int i = 0; i < k; i++) {
//                 if (lists[i] != NULL) {
//                     temp.push_back(lists[i]->val);
//                     lists[i] = lists[i]->next;
//                 }
//             }

//             if (temp.size() == 0) {
//                 run = false;
//             }

//             // sort the temp vector
//             sort(temp.begin(), temp.end());

//             // add the sorted vector to the answer linked list
//             for (int i = 0; i < temp.size(); i++) {
//                 if (answer == NULL) {
//                     answer = new ListNode(temp[i]);
//                 } else {
//                     ListNode* temp2 = answer;
//                     while (temp2->next != NULL) {
//                         temp2 = temp2->next;
//                     }
//                     temp2->next = new ListNode(temp[i]);
//                 }
//             }
//         }

//         answer = answer->next;
//         return answer;
//     }
// };

// ListNode* solve(ListNode* first, ListNode* second) {
//     ListNode* curr1 = first;
//     ListNode* next1 = curr1->next;
//     ListNode* curr2 = second;
//     ListNode* next2 = curr2->next;

//     while (next1 != NULL && curr2 != NULL) {
//         // curr1 = 1--3
//         // curr2 = 2
//         // check if curr2 lies between 1 & 3
//         if ((curr2->val >= curr1->val) && (curr2->val <= next1->val)) {
//             curr1->next = curr2;

//             // keeps part of curr2 intact <------- THIS 5 steps is GAME
//             next2 = curr2->next;
//             curr2->next = next1;
//             curr1 = curr2;
//             curr2 = next2;
//         } else {
//             curr1 = next1;
//             next1 = next1->next;

//             if (next1 == NULL) {
//                 curr1->next = curr2;
//                 return first;
//             }
//         }
//     }

//     return first;
// }

// merge two sorted linked lists
ListNode* merge(ListNode* first, ListNode* second) {
    if (first == NULL) {
        return second;
    }

    if (second == NULL) {
        return first;
    }

    ListNode* result = NULL;

    if (first->val <= second->val) {
        result = first;
        result->next = merge(first->next, second);
    } else {
        result = second;
        result->next = merge(first, second->next);
    }

    return result;
}

ListNode* mergeSort(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* second = slow->next;
    slow->next = NULL;

    ListNode* first = mergeSort(head);
    second = mergeSort(second);

    ListNode* ans = merge(first, second);
    return ans;
}

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // loop through the lists and connect them
        ListNode* head = NULL;
        for (int i = 0; i < lists.size(); i++) {
            if (head == NULL) {
                head = lists[i];
            } else {
                ListNode* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = lists[i];
            }
        }

        // sort the linked list
        head = mergeSort(head);
        return head;
    }
};

int main() {
    vector<vector<int>> v = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}};

    vector<ListNode*>
        lls = multiVecToMultiLL(v);

    Solution sol;
    ListNode* ans = sol.mergeKLists(lls);

    printLL(ans);

    // cout << lls[0]->next->val << endl;
}