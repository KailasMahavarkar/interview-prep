#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node* left, Node* right) : data(x), left(left), right(right) {}
};

Node* vectorToTree(vector<int>& tree) {
    if (tree.size() == 0) {
        return NULL;
    }

    Node* root = new Node(tree[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (i < tree.size()) {
        Node* temp = q.front();
        q.pop();

        if (tree[i] != -1) {
            temp->left = new Node(tree[i]);
            q.push(temp->left);
        }
        i++;
        if (i >= tree.size()) {
            break;
        }

        if (tree[i] != -1) {
            temp->right = new Node(tree[i]);
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
    Node* rootNode;

    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;

        while (curr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->data);
            }

            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }

            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        if (root->left) {
            addLeaves(root->left, res);
        }

        if (root->right) {
            addLeaves(root->right, res);
        }
    }

    vector<int> boundary(Node* root) {
        vector<int> answer;

        if (!root) {
            return answer;
        }

        if (!isLeaf(root)) {
            answer.push_back(root->data);
        }

        addLeftBoundary(root, answer);
        addLeaves(root, answer);
        addRightBoundary(root, answer);

        return answer;
    };
};

int main() {
    vector<int> root = {1, 2, 3, 4, 5, 6, 7, -1, -1, 8, 9, -1, -1, -1, -1};

    Solution sol;
    vector<int> answer = sol.boundary(
        vectorToTree(root));

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}