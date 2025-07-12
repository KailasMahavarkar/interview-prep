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
    bool checkTree(TreeNode* root) {
        if (!root) {
            return true;
        }

        if (!root->left && !root->right) {
            return true;
        }

        int sumNow = root->val;

        if (root->left) {
            sumNow -= root->left->val;
        }

        if (root->right) {
            sumNow -= root->right->val;
        }

        if (sumNow == 0 && checkTree(root->left) && checkTree(root->right)) {
            return true;
        }
        return false;
    }
};

int main() {
    vector<int> root = {10, 4, 6};

    Solution sol;
    bool answer = sol.checkTree(vectorToTree(root));
    cout << "answer: " << boolalpha << answer << endl;

    return 0;
}