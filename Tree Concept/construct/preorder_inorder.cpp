#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
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
    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        int preStart = 0, preEnd = preOrder.size() - 1;
        int inStart = 0, inEnd = inOrder.size() - 1;

        map<int, int> hmap;
        for (int i = 0; i <= inEnd; i++) {
            hmap[inOrder[i]] = i;
        }

        return constructTree(preOrder, hmap, preStart, preEnd, inStart, inEnd);
    }

    TreeNode* constructTree(vector<int>& preOrder, map<int, int>& hmap, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // since the 1st element is root
        TreeNode* root = new TreeNode(preOrder[preStart]);

        // find position of root's value in inorder
        int pivot = hmap[root->val];
        int numsLeft = pivot - inStart;

        root->left = constructTree(preOrder, hmap, preStart + 1, preStart + numsLeft, inStart, pivot - 1);
        root->right = constructTree(preOrder, hmap, preStart + numsLeft + 1, preEnd, pivot + 1, inEnd);
        return root;
    }
};

int main() {
    vector<int> vec = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode* root = vectorToTree(vec);
    vector<int> preOrderResult = {3, 9, 20, 15, 7};
    vector<int> inOrderResult = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* newTree = sol.buildTree(preOrderResult, inOrderResult);
    levelOrderTree(newTree);

    return 0;
}