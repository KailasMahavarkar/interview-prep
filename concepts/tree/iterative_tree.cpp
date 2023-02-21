#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *vectorToTree(vector<int> v) {
    if (v.size() == 0) {
        return NULL;
    }

    TreeNode *root = new TreeNode(v[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < v.size()) {
        TreeNode *temp = q.front();
        q.pop();

        if (v[i] != -1) {
            temp->left = new TreeNode(v[i]);
            q.push(temp->left);
        }
        i++;

        if (i < v.size() && v[i] != -1) {
            temp->right = new TreeNode(v[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

vector<vector<int>> levelOrderTraversal(TreeNode *root) {
    vector<vector<int>> ans;

    if (root == NULL) {
        return ans;
    }
    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode *temp = que.front();
            que.pop();

            if (temp->left) {
                que.push(temp->left);
            }

            if (temp->right) {
                que.push(temp->right);
            }

            level.push_back(temp->val);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<int> iterativePreorder(TreeNode *root) {
    vector<int> preorder;
    if (root == NULL) return preorder;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode *temp = st.top();
        st.pop();

        preorder.push_back(temp->val);

        if (temp->right) {
            st.push(temp->right);
        }
        if (temp->left) {
            st.push(temp->left);
        }
    }

    return preorder;
}
  
vector<int> iterativeInorder(TreeNode *root){

}

int main() {
    vector<int> treeNums = {3, 2, 1, NULL, NULL, NULL, NULL};
    vector<int> ans = iterativePreorder(vectorToTree(treeNums));

    for (auto x : ans) {
        cout << x << " ";
    }
}