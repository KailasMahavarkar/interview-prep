#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Definition for a binary tree TreeNode.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void preOrder(TreeNode *root) {
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

void levelOrderTraversal(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();

        if (temp == NULL) {
            // purana wala complete traverse ho chuka h
            cout << endl;      // enter marna
            if (!q.empty()) {  // queue still has child nodes
                q.push(NULL);
            }
        } else {
            cout << temp->val << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

TreeNode *vectorToTree(vector<int> v) {
    if (v.size() == 0) {
        return NULL;
    }

    TreeNode *root = new TreeNode(v[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < v.size()) {
        TreeNode *temp = q.front();
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

class Solution {
   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;

        if (root == NULL) {
            return result;
        }

        queue<TreeNode *> que;
        que.push(root);

        bool leftToRight = true;

        while (!que.empty()) {
            int size = que.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode *temp = que.front();
                que.pop();

                // find position to fill node's value
                int index = (leftToRight) ? i : size - 1 - i;

                level[index] = temp->val;

                if (temp->left) {
                    que.push(temp->left);
                }

                if (temp->right) {
                    que.push(temp->right);
                }
            }
            
            leftToRight = !leftToRight;
            result.push_back(level);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {3, 9, 20, NULL, NULL, 15, 7};
    Solution sol;
    vector<vector<int>> result = sol.zigzagLevelOrder(
        vectorToTree(nums));

    // levelOrderTraversal();
    for (auto x : result) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}