#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* vectorToTree(vector<int> vec) {
    TreeNode* root = new TreeNode(vec[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < vec.size()) {
            curr->left = new TreeNode(vec[i]);
            q.push(curr->left);
            i++;
        }
        if (i < vec.size()) {
            curr->right = new TreeNode(vec[i]);
            q.push(curr->right);
            i++;
        }
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
    TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
        unordered_map<int, int> hmap;
        for (int i = 0; i < inOrder.size(); i++) {
            hmap[inOrder[i]] = i;
        }

        return constructTree(postOrder, hmap, 0, postOrder.size() - 1, 0, inOrder.size() - 1);
    }

    TreeNode* constructTree(vector<int>& postOrder, unordered_map<int, int>& hmap, int postStart, int postEnd, int inStart, int inEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postOrder[postEnd]);
        int inRoot = hmap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = constructTree(postOrder, hmap, postStart, postStart + numsLeft - 1, inStart, inRoot - 1);
        root->right = constructTree(postOrder, hmap, postStart + numsLeft, postEnd - 1, inRoot + 1, inEnd);
        return root;
    }
};

int main() {
    vector<int> vec = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode* root = vectorToTree(vec);
    vector<int> postOrderResult = {9, 15, 7, 20, 3};
    vector<int> inOrderResult = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* newTree = sol.buildTree(inOrderResult, postOrderResult);
    levelOrderTree(newTree);

    return 0;
}