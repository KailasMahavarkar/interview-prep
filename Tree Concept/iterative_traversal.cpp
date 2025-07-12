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

void levelOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

// using single stack
vector<int> iterativePreorder(TreeNode* root) {
    vector<int> preorder;
    if (root == NULL) return preorder;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        root = st.top();
        st.pop();

        preorder.push_back(root->val);

        if (root->right != NULL) {
            st.push(root->right);
        }

        if (root->left != NULL) {
            st.push(root->left);
        }
    }

    return preorder;
}

// using single stack
vector<int> iterativeInorder(TreeNode* root) {
    vector<int> inorder;
    if (!root) return inorder;

    stack<TreeNode*> st;
    TreeNode* node = root;

    while (true) {
        // when we dont have null element
        // means we can still go left
        if (node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty() == true) break;
            node = st.top();
            st.pop();

            inorder.push_back(node->val);
            node = node->right;
        }
    }

    return inorder;
}

int main() {
    vector<int> vec = {1, -1, 2, 3, 4, 6, 9, 6, 8};

    // convert vector to tree
    TreeNode* root = vectorToTree(vec);
    levelOrder(root);

    vector<int> result = iterativeInorder(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}