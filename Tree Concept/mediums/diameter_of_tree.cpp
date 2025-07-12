#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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

class Solution {
   public:
    int findDiameter(TreeNode* root, int& answer) {
        if (!root) {
            return 0;
        }

        int left = findDiameter(root->left, answer);
        int right = findDiameter(root->right, answer);

        answer = max(answer, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int answer = 0;
        findDiameter(root, answer);
        return answer;
    }
};

int main() {
    // vector<int> root = {3, 9, 20, -1, -1, 15, 7};
    vector<int> root = {1, 2, 3, 4, 5};

    Solution sol;
    int answer = sol.diameterOfBinaryTree(vectorToTree(root));
    cout << "isBalanced: " << answer << endl;
}