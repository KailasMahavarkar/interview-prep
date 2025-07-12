#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/delete-leaves-with-a-given-value/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* vectorToTree(vector<int>& tree) {
    if (tree.size() == 0) {
        return NULL;
    }

    TreeNode* root = new TreeNode(tree[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < tree.size()) {
        TreeNode* temp = q.front();
        q.pop();

        if (tree[i] != -1) {
            temp->left = new TreeNode(tree[i]);
            q.push(temp->left);
        }
        i++;
        if (i >= tree.size()) {
            break;
        }

        if (tree[i] != -1) {
            temp->right = new TreeNode(tree[i]);
            q.push(temp->right);
        }
        i++;
    }

    return root;
}

void levelOrderTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
        int levelSize = que.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* temp = que.front();
            que.pop();

            cout << temp->val << " ";

            if (temp->left) {
                que.push(temp->left);
            }
            if (temp->right) {
                que.push(temp->right);
            }
        }
    }
    cout << endl;
}

// Approach-1 (Normal)
// TC : O(n)
// SC : O(depth of tree) -> O(n)
class Solution {
   public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            return nullptr;
        }

        return root;
    }
};


int main() {
    Solution sol;
    vector<int> nodes = {1, 2, 3, 2, -1, 2, 4};
    TreeNode* root = vectorToTree(nodes);

    TreeNode* answer = sol.removeLeafNodes(root, 2);
    levelOrderTree(answer);
}
