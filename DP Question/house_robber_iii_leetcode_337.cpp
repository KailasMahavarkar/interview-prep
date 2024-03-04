#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/house-robber-iii/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/DP/House%20Robber%20III.cpp
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

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
    unordered_map<TreeNode*, int> mp_not_rob;
    unordered_map<TreeNode*, int> mp_rob;
    int solve(TreeNode* root, bool parentRobbed) {
        if (!root)
            return 0;

        if (parentRobbed) {
            if (mp_not_rob.find(root) != mp_not_rob.end()) {
                return mp_not_rob[root];
            }
            return mp_not_rob[root] = solve(root->left, false) + solve(root->right, false);
        }

        if (mp_rob.find(root) != mp_rob.end()) {
            return mp_rob[root];
        }

        int rob = root->val + solve(root->left, true) + solve(root->right, true);
        int not_rob = solve(root->left, false) + solve(root->right, false);
        return mp_rob[root] = max(rob, not_rob);
    }
    int rob(TreeNode* root) {
        return solve(root, false);
    }
};

int main() {
    vector<int> treeData = {3, 2, 3, -1, 3, -1, 1};
    Solution sol;
    int answer = sol.rob(vectorToTree(treeData));
    cout << "ans --> " << answer << endl;
}
