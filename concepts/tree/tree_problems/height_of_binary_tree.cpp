#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* vectorToTree(vector<int> v) {
    if (v.size() == 0) {
        return NULL;
    }

    node* root = new node(v[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < v.size()) {
        node* temp = q.front();
        q.pop();

        if (v[i] != -1) {
            temp->left = new node(v[i]);
            q.push(temp->left);
        }
        i++;

        if (i < v.size() && v[i] != -1) {
            temp->right = new node(v[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // purana wala complete traverse ho chuka h
            cout << endl;      // enter marna
            if (!q.empty()) {  // queue still has child nodes
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

node* buildTree(node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1) {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

class Solution {
   public:
    int maxDepth(node* root) {
        // base case
        if (root == NULL) {
            return 0;
        }

        // left ko pura explore karo
        int leftDepth = maxDepth(root->left);

        // right ko pura explore karo
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    vector<int> base = {10, 20, 30, -1, -1, -1, 40};
    node* root = vectorToTree(base);


    Solution sol;
    cout << sol.maxDepth(root) << endl;
    return 0;
}