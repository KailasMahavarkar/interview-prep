#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // either we reaches null node or we did not found the val
        // continue searching in that case
        while (root != NULL && root->val != val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;
    }
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

int main() {
    vector<int> vec = {1, -1, 2, 3, 4, 6, 9, 6, 8};

    // convert vector to tree
    TreeNode* root = vectorToTree(vec);
    levelOrder(root);

    vector<int> result = iterativeInorder(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}  