#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

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

class Solution {
   public:
    int findHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left = findHeight(root->left);
        int right = findHeight(root->right);

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int left = findHeight(root->left);
        int right = findHeight(root->right);

        if (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    }
};

int main() {
    // vector<int> root = {3, 9, 20, -1, -1, 15, 7};
    vector<int> root = {1, 2, 2, 3, 3, -1, -1, 4, 4};

    Solution sol;
    bool answer = sol.isBalanced(vectorToTree(root));
    cout << "isBalanced: " << boolalpha << answer << endl;
}