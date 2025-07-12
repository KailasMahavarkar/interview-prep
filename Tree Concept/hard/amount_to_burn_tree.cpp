#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
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

void printVI(vector<int> vec) {
    for (auto x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

TreeNode* findNode(TreeNode* root, int target) {
    if (!root) {
        return new TreeNode(-1);
    };

    queue<TreeNode*> que;
    que.push(root);
    int level = 0;

    while (!que.empty()) {
        int levelSize = que.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = que.front();
            que.pop();

            if (node->val == target) {
                return node;
            }
            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }
        level++;
    }

    return new TreeNode(-1);
}

class Solution {
   public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent_track;  // node -> parent
        TreeNode* target = findNode(root, start);

        markParents(root, parent_track, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                if (current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            curr_level++;
        }

        return curr_level - 1;
    }
};

int main() {
    vector<int> values = {1, 5, 3, -1, 4, 10, 6, 9, 2};
    TreeNode* root = vectorToTree(values);
    int start = 3;

    Solution sol;
    int answer = sol.amountOfTime(root, start);
    cout << "answer -->" << answer << endl;

    return 0;
}