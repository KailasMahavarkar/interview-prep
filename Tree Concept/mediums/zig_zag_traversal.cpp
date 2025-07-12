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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (!root) {
            return result;
        }

        queue<TreeNode*> que;
        que.push(root);

        bool LTR = true;

        while (!que.empty()) {
            int levelSize = que.size();
            vector<int> subResult(levelSize);

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                int index = LTR ? i : levelSize - i - 1;

                subResult[index] = node->val;

                if (node->left) {
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }
            }
            LTR = !LTR;
            result.push_back(subResult);
        }

        return result;
    }
};

int main() {
    vector<int> root = {3, 9, 20, -1, -1, 15, 7};

    Solution sol;
    vector<vector<int>> answer = sol.zigzagLevelOrder(vectorToTree(root));
    printVVI(answer);
}