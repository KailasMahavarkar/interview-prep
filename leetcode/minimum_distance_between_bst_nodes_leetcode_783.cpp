#include <algorithm>
#include <climits>
#include <iostream>
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

class Solution {
   public:
    int minHelper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int leftMin = minHelper(root->left);
        int rightMin = minHelper(root->right);

        return min(root->val - leftMin, root->val - rightMin);
    }
    int minDiffInBST(TreeNode *root) {
		return minHelper(root);
    }
};

int main() {
}