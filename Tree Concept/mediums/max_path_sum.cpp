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
    int solve(TreeNode* root, int& answer) {
        if (!root) {
            return 0;
        }

        int leftSum = max(0, solve(root->left, answer));
        int rightSum = max(0, solve(root->right, answer));

        // two candidates possibilites for answer
        // 1. previous answer (answer so far) 
        // 2. sum of left path and right path + current node
        answer = max(answer, root->val + leftSum + rightSum);

        // we only send max value from left path or right to top
        return root->val + max(leftSum + rightSum);
    }

    int maxPathSum(TreeNode* root) {
        // run test case = [1, -1, 4, -3, 6, null, null, 5, null, null, null]
        //           1
        //        -1    4
        //      -3  6  x  x
        //     5 x x x

        // final answer is (6) + (-1) + (1) + (4) = 10
        int answer = INT_MIN;
        solve(root, answer);
        return answer;
    }
};

int main() {
    // vector<int> root = {3, 9, 20, -1, -1, 15, 7};
    // vector<int> root = {-10, 9, 20, -1, -1, 15, 7};
    // vector<int> root = {1, 2, 3};

    Solution sol;
    int answer = sol.maxPathSum(vectorToTree(root));
    cout << "isBalanced: " << answer << endl;
}