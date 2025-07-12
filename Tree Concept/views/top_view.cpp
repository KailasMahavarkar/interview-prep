#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <utility>
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
    vector<int> topView(Node* root) {
        vector<int> answer;

        if (!root) return answer;

        map<int, int> mp;
        queue<pair<Node*, int>> que;
        que.push({root, 0});

        while (!que.empty()) {
            auto p = que.front();
            que.pop();

            Node* node = p.first;
            int vertical = p.second;

            // top view: add to map only if does not exist
            // bottom view: add to map anyways
            if (mp.find(vertical) == mp.end()) {
                mp[vertical] = node->data;
            }

            if (node->left) {
                que.push({node->left, vertical - 1});
            }

            if (node->right) {
                que.push({node->right, vertical + 1});
            }
        }

        for (auto it : mp) {
            answer.push_back(it.second);
        }

        return answer;
    }
};

int main() {
    vector<int> root = {1, 2, 3, -1, 4, 5, -1, 6, -1, 7, -1, 8, -1, 9, -1, -1, -1, -1, -1};

    Solution sol;
    vector<int> answer = sol.topView(vectorToTree(root));

    for (auto x : answer) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}