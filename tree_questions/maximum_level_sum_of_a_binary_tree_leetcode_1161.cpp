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

class Solution {
   public:
    int maxLevelSum(TreeNode* root) {
        int globalBest = INT_MIN;
        int globalBestIndex = 0;
        int level = 1;  // root is 1 level

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int levelSize = que.size();
            int currSum = 0;

            while (levelSize--) {
                TreeNode* node = que.front();
                que.pop();
                currSum += node->val;

                if (node->left) {
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }
            }

            if (currSum > globalBest) {
                globalBest = currSum;
                globalBestIndex = level;
            }

            level++;
        }

        return globalBestIndex;
    }
};

int main() {
    vector<int> root = {1, 7, 0, 7, -8, -1, -1};

    Solution sol;
    int answer = sol.maxLevelSum(vectorToTree(root));
    cout << "max level sum: " << answer << endl;
}