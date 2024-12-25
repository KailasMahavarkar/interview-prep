#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/range-sum-query-mutable/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Segment Tree)
// TC : O(n) for build, O(log(n)) for update/query
// SC : O(4 * n) for storing the segment tree
class NumArray {
   public:
    vector<int> tree;
    vector<int> nums;
    int n;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        tree.resize(4 * n, 0);
        buildTree(0, 0, n - 1);
    }

    void buildTree(int idx, int l, int r) {
        if (l == r) {
            tree[idx] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildTree(2 * idx + 1, l, mid);
        buildTree(2 * idx + 2, mid + 1, r);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void updateTree(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            updateTree(2 * idx + 1, l, mid, pos, val);
        } else {
            updateTree(2 * idx + 2, mid + 1, r, pos, val);
        }

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int queryTree(int idx, int l, int r, int s, int e) {
        if (l > e || r < s) return 0;
        if (l >= s && r <= e) return tree[idx];

        int mid = l + (r - l) / 2;
        int leftSum = queryTree(2 * idx + 1, l, mid, s, e);
        int rightSum = queryTree(2 * idx + 2, mid + 1, r, s, e);
        return leftSum + rightSum;
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return queryTree(0, 0, n - 1, left, right);
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);

    cout << "Initial sumRange(0, 2): " << obj->sumRange(0, 2) << endl;
    obj->update(1, 2);
    cout << "Updated sumRange(0, 2): " << obj->sumRange(0, 2) << endl;

    delete obj;
    return 0;
}
