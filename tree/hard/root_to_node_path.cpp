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

void printVVI(vector<vector<int>> vec) {
    for (auto subvec : vec) {
        for (auto x : subvec) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
   public:
    bool getPathNodes(TreeNode* root, vector<int>& arr, int target) {
        if (!root) {
            return false;
        }

        arr.push_back(root->val);

        if (root->val == target) {
            return true;
        }

        if (getPathNodes(root->left, arr, target) || getPathNodes(root->right, arr, target)) {
            return true;
        }
        // backtrack to clear prev arr result
        arr.pop_back();
        return false;
    }
    vector<int> getPath(TreeNode* root, int target) {
        vector<int> arr;
        if (!root) {
            return arr;
        }

        getPathNodes(root, arr, target);
        return arr;
    }
};

int main() {
    vector<int> root = {1, 2, 3, -1, 4, 5, -1, 6, -1, 7, -1, 8, -1, 9, -1, -1, -1, -1, -1};

    Solution sol;
    vector<int> answer = sol.getPath(vectorToTree(root), 7);

    for (auto x : answer) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}