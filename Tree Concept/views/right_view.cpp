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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;

        if (!root) return answer;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int levelSize = que.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (i == levelSize - 1) {
                    answer.push_back(node->val);
                }

                if (node->left) {
                    que.push(node->left);
                }

                if (node->right) {
                    que.push(node->right);
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> root = {1, 2, 3, -1, 5, -1, 4};

    Solution sol;
    vector<int> answer = sol.rightSideView(vectorToTree(root));

    for (auto x : answer) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}