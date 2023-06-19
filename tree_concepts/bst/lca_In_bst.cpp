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

void levelOrderTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
        int levelSize = que.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* temp = que.front();
            que.pop();

            cout << temp->val << " ";

            if (temp->left) {
                que.push(temp->left);
            }
            if (temp->right) {
                que.push(temp->right);
            }
        }
    }
    cout << endl;
}

class Solution {
   public:
    /*
        if both p and q are less than curr,
        then the LCA must be in the left subtree of the current node,
        so the function recurses on the left subtree.

        If neither of these conditions is true,
        then it means that p and q are on different sides of the current node
    */

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }

        int curr = root->val;
        if (curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};

int main() {
    vector<int> tree = {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    TreeNode* root = vectorToTree(tree);

    levelOrderTree(root);
    Solution s;

    TreeNode* res = s.lowestCommonAncestor(root, root->left, root->right);
    cout << res->val << endl;

    return 0;
}