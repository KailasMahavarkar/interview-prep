#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

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

class Solution {
   public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        TreeNode* curr = root;
        while (true) {
            if (val >= curr->val) {
                // go right
                if (curr->right == NULL) {
                    curr->right = new TreeNode(val);
                    break;
                } else {
                    curr = curr->right;
                }
            } else {
                // go left
                if (curr->left == NULL) {
                    curr->left = new TreeNode(val);
                    break;
                } else {
                    curr = curr->left;
                }
            }
        }
        return root;
    }
};

int main() {
    vector<int> vec = {4, 2, 7, 1, 3};

    // convert vector to tree
    TreeNode* root = vectorToTree(vec);

    Solution sol;
    root = sol.insertIntoBST(vectorToTree(vec), 5);
    levelOrderTree(root);
    cout << endl;
}