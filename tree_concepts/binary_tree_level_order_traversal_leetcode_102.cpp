#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> answer;

        if (!root) {
            return answer;
        }

        queue<TreeNode *> que;
        que.push(root);
        que.push(NULL);

        vector<int> level;
        while (!que.empty()) {
            TreeNode *temp = que.front();
            que.pop();

            if (temp == NULL) {
                answer.push_back(level);
                level.clear();

                if (!que.empty()) {
                    que.push(NULL);
                }
            } else {
                // cout << temp->val << " ";
                level.push_back(temp->val);
                if (temp->left) {
                    que.push(temp->left);
                }
                if (temp->right) {
                    que.push(temp->right);
                }
            }
        }

        return answer;
    }
};

void printVVI(vector<vector<int>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

TreeNode *vectorToTree(vector<int> arr) {
    if (arr.size() == 0) {
        return NULL;
    }

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> que;
    que.push(root);

    int idx = 1;
    while (!que.empty()) {
        TreeNode *node = que.front();
        que.pop();

        if (idx < arr.size()) {
            if (arr[idx] != -1) {
                node->left = new TreeNode(arr[idx]);
                que.push(node->left);
            }
            idx++;
        }

        if (idx < arr.size()) {
            if (arr[idx] != -1) {
                node->right = new TreeNode(arr[idx]);
                que.push(node->right);
            }
            idx++;
        }
    }

    return root;
}

int main() {
    vector<int> arr = {3, 9, 20, NULL, NULL, 15, 7};
    TreeNode *root = vectorToTree(arr);
    Solution sol;
    vector<vector<int>> answer = sol.levelOrder(root);
    printVVI(answer);
}