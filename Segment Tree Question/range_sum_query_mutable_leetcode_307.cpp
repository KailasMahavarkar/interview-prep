#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
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

    void buildTree(int nodeIdx, int ns, int ne) {
        if (ns == ne) {
            tree[nodeIdx] = nums[ns];
            return;
        }

        int mid = ns + (ne - ns) / 2;
        buildTree(2 * nodeIdx + 1, ns, mid);
        buildTree(2 * nodeIdx + 2, mid + 1, ne);
        tree[nodeIdx] = tree[2 * nodeIdx + 1] + tree[2 * nodeIdx + 2];
    }

    void updateTree(int nodeIdx, int ns, int ne, int pos, int val) {
        if (ns == ne) {
            tree[nodeIdx] = val;
            return;
        }

        int mid = ns + (ne - ns) / 2;

        if (pos <= mid) {
            updateTree(2 * nodeIdx + 1, ns, mid, pos, val);
        } else {
            updateTree(2 * nodeIdx + 2, mid + 1, ne, pos, val);
        }
        tree[nodeIdx] = tree[2 * nodeIdx + 1] + tree[2 * nodeIdx + 2];
    }

    int queryTree(int nodeIdx, int qs, int qe, int ns, int ne) {
        //                 qs------------------qe
        //    ns-------ne                         ns------ne
        if (qs > ne || qe < ns) {
            return 0;
        }

        //                 qs------------------qe
        //                       ns-------ne
        if (qs <= ns && qe >= ne) {
            return tree[nodeIdx];
        }

        int mid = ns + (ne - ns) / 2;
        int leftSum = queryTree(2 * nodeIdx + 1, qs, qe, ns, mid);
        int rightSum = queryTree(2 * nodeIdx + 2, qs, qe, mid + 1, ne);
        return leftSum + rightSum;
    }

    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val);
    }

    int sumRange(int qs, int qe) {
        return queryTree(0, qs, qe, 0, n - 1);
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
