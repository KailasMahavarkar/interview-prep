#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class TreeNode
{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
public:
    string tree2str(TreeNode *&t){
        if (t == nullptr){
            return "";
        }
        if (t->left == nullptr && t->right == nullptr){
            return to_string(t->val) + "";
        }
        if (t->right == nullptr){
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        }
        return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }
};