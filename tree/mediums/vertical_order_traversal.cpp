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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;

        // map<vertical, map<level, nodes[]>>
        // vertical is -X to +X | level is 0 to N

        map<int, map<int, multiset<int>>> mp;

        if (!root) {
            return answer;
        }

        queue<pair<TreeNode*, pair<int, int>>> que;
        que.push({root, {0, 0}});

        while (!que.empty()) {
            int levelSize = que.size();
            int level = 0;

            auto p = que.front();
            que.pop();

            TreeNode* node = p.first;

            int v = p.second.first;   // vertical
            int l = p.second.second;  // level

            mp[v][l].insert(node->val);

            if (node->left) {
                que.push({node->left, {v - 1, l + 1}});
            }

            if (node->right) {
                que.push({node->right, {v + 1, l + 1}});
            }
        }

        // verticalMap will be pair<int, map<int, multiset<int>>>
        for (auto verticalMap : mp) {
            vector<int> cols;

            // levelMap will be pair<int, multiset<int>>
            for (auto levelMap : verticalMap.second) {
                cols.insert(cols.end(), levelMap.second.begin(), levelMap.second.end());
            }
            // sort(cols.begin(), cols.end(), greater<int>());
            answer.push_back(cols);
        }

        return answer;
    }
};

int main() {
    vector<int> root = {3, 1, 4, 0, 2, 2};

    Solution sol;
    vector<vector<int>> answer = sol.verticalTraversal(vectorToTree(root));

    printVVI(answer);

    return 0;
}