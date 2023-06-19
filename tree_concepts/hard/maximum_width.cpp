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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});
        long answer = 0;

        while (!que.empty()) {
            int levelSize = que.size();
            long start = que.front().second;
            long end = que.back().second;
            answer = max(answer, end - start + 1);

            for (int i = 0; i < levelSize; i++) {
                auto x = que.front();
                que.pop();

                TreeNode* node = x.first;
                long idx = x.second;

                if (node->left) {
                    que.push({node->left, 2 * idx + 1});
                }

                if (node->right) {
                    que.push({node->right, 2 * idx + 2});
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<int> root = {1, 3, 2, 5, 3, -1, 9};

    Solution sol;
    int answer = sol.widthOfBinaryTree(vectorToTree(root));
    cout << "answer: " << answer << endl;

    return 0;
}