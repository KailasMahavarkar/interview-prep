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

class Solution {
   public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }

    TreeNode* construct(vector<int>& nums, int s, int e) {
        if (s > e) {
            return NULL;
        }
        if (s == e) {
            return new TreeNode(nums[s]);
        }

        int pivot = findMax(nums, s, e);
        TreeNode* root = new TreeNode(nums[pivot]);
        root->left = construct(nums, s, pivot - 1);
        root->right = construct(nums, pivot + 1, e);
        return root;
    }

    int findMax(vector<int>& nums, int s, int e) {
        int maxx = INT_MIN;
        int idx = -1;
        for (int i = s; i <= e; i++) {
            if (nums[i] > maxx) {
                maxx = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};

void levelOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

int main() {
    Solution* sol = new Solution();
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode* root = sol->constructMaximumBinaryTree(nums);
    levelOrder(root);
    return 0;
}