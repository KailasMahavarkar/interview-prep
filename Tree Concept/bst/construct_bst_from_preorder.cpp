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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;

        // when key is found
        if (root->val == key) {
            return helper(root);
        }

        // this is savepoint since later we will traverse root
        TreeNode* curr = root;

        // use this snapshot as reference | delete node 5
        // https://i.imgur.com/iZtn0Te.png
        // playlist: https://youtu.be/kouxiP_H5WE?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&t=598

        while (root != NULL) {
            if (key > root->val) {
                // search right
                // Note: notice the (root->right->val)
                if (root->right != NULL && root->right->val == key) {
                    // delete node
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            } else {
                // search left
                if (root->left != NULL && root->left->val == key) {
                    // delete node
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            }
        }

        return curr;
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findLastRight(root->right);
    }
};

int main() {
    vector<int> vec = {5, 3, 6, 2, 4, -1, 7};

    // convert vector to tree
    TreeNode* root = vectorToTree(vec);

    Solution sol;
    root = sol.deleteNode(vectorToTree(vec), 3);
    levelOrderTree(root);
    cout << endl;
}