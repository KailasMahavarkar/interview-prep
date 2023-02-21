#include <bits/stdc++.h>
using namespace std;

class node {
   public:
    int data;
    node* left;
    node* right;

    // constructor
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// convert vector of int to tree
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
                // q.push(NULL);
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

void inorderTraversal(node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    // inorder - LNR

    // L -> go left
    inorderTraversal(root->left);
    // N -> print node
    cout << root->data << " ";
    // R -> go right
    inorderTraversal(root->right);
}

void preorderTraversal(node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    // preorder -> NLR

    // N -> print node
    cout << root->data << " ";

    // L -> go left
    preorderTraversal(root->left);
    // R -> go right
    preorderTraversal(root->right);
}

void postorder(node* root) {
    // base case
    if (root == NULL) {
        return;
    }

    // recurse left
    postorder(root->left);

    // recurse right
    postorder(root->right);

    // print
    cout << root->data << " ";
}

void printLevelOrder(node* root) {
    queue<node*> que;
    que.push(root);
    que.push(NULL);

    while (!que.empty()) {
        node* temp = que.front();
        que.pop();

        if (temp == NULL) {
            // enter marna padega
            cout << endl;
            if (!que.empty()) {
                que.push(NULL);
            }
        } else {
            cout << temp->data << " ";

            if (temp->left) {
                que.push(temp->left);
            }

            if (temp->right) {
                que.push(temp->right);
            }
        }
    }
}

int main() {
    node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 2 4 -1 -1 3 -1 -1 -1

    // create A tree
    // root = buildTree(root);

    vector<int> base = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1};
    root = vectorToTree(base);
    // levelOrderTraversal(root);
    // inorderTraversal(root);

    printLevelOrder(root);

    return 0;
}