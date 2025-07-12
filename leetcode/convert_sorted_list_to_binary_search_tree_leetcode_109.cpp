#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* vectorToTree(vector<int> v) {
    if (v.size() == 0) {
        return NULL;
    }

    TreeNode* root = new TreeNode(v[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < v.size()) {
        TreeNode* temp = q.front();
        q.pop();

        if (v[i] != -1) {
            temp->left = new TreeNode(v[i]);
            q.push(temp->left);
        }
        i++;

        if (i < v.size() && v[i] != -1) {
            temp->right = new TreeNode(v[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

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

// print tree
void preOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";

    if (root->left) {
        preOrder(root->left);
    }

    if (root->right) {
        preOrder(root->right);
    }
}

class Solution {
   public:
    TreeNode* sortedListToBST(ListNode* head) {

        // when there are no elements in LL
        // its generated tree should also have no elements
        if (head == NULL) {
            return NULL;
        }

        // when only single element is present in LL
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // mid is slow at this point
        TreeNode* root = new TreeNode(slow->val);

        // break LL into two parts
        slow_prev->next = NULL;

        // recursively slow left
        // for left half starting point is head
        root->left = sortedListToBST(head);

        // for right half starting point is (mid.next)
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

int main() {
    Solution sol;

    vector<int> linkedList = {-10, -3, 0, 5, 9};

    TreeNode* tree = sol.sortedListToBST(vectorToList(linkedList));
    preOrder(tree);
}