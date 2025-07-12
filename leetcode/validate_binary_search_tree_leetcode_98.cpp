#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// convert vector of int to tree
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
    void inorderTraversal(TreeNode *root) {
        
    }
    bool isValidBST(TreeNode *root) {
        return true;
    }
};

int main() {
    // vector<int> base = {5, 1, 4, NULL, NULL, 3, 6};
    vector<int> base = {3, 2, 5, NULL, NULL, 7};

    Solution sol;

    bool ans = sol.isValidBST(vectorToTree(base));
    cout << boolalpha << ans << endl;
}