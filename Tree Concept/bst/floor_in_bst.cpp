#include <algorithm>
#include <climits>
#include <cmath>
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

class Solution {
   public:
    int floorBST(TreeNode* root, int key) {
        int floor = -1;
        while (root) {
            if (root->val == key) {
                return root->val;
            }

            // when current is smaller and we have to discard it and move right
            if (root->val > key) {
                root = root->left;
            } else {
                floor = root->val;
                root = root->right;
            }
        }
        return floor;
    }
};

int main() {
    vector<int> vec = {1, 2, 5, 7, 8, 9};
    TreeNode* root = vectorToTree(vec);

    Solution sol;
    int ans = sol.floorBST(root, 8);
    cout << "answer -->" << ans << endl;
}