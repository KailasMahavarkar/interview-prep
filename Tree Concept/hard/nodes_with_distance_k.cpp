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

int findDepth(TreeNode* root, TreeNode* target) {
    if (!root) {
        return -1;
    };
    queue<TreeNode*> que;
    que.push(root);
    int level = 0;

    while (!que.empty()) {
        int levelSize = que.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node == target) {
                return level;
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

    return -1;
}

class Solution {
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

   public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;  // node -> parent
        markParents(root, parent_track, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while (!queue.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = queue.size();
            if (curr_level++ == k) break;
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
        }
        vector<int> result;
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};

int main() {
    vector<int> values = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode* root = vectorToTree(values);
    TreeNode* target = root->left->right;
    int k = 2;

    Solution sol;
    vector<int> answer = sol.distanceK(root, target, k);
    printVI(answer);

    return 0;
}