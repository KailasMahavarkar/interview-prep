#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class SegmentTree {
   public:
    vector<int> tree;
    vector<int> nums;
    vector<int> lazy;
    int n;

    SegmentTree(vector<int>& input) {
        nums = input;
        n = input.size();
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        buildTree(0, 0, n - 1);
    }

   private:
    void buildTree(int nodeIdx, int nodeStart, int nodeEnd) {
        if (nodeStart == nodeEnd) {
            tree[nodeIdx] = nums[nodeStart];
            return;
        }

        int mid = nodeStart + (nodeEnd - nodeStart) / 2;
        buildTree(2 * nodeIdx + 1, nodeStart, mid);
        buildTree(2 * nodeIdx + 2, mid + 1, nodeEnd);
        tree[nodeIdx] = tree[2 * nodeIdx + 1] + tree[2 * nodeIdx + 2];
    }

    void updateTree(int nodeIdx, int nodeStart, int nodeEnd, int pos, int val) {
        if (nodeStart == nodeEnd) {
            tree[nodeIdx] = val;
            return;
        }

        int mid = nodeStart + (nodeEnd - nodeStart) / 2;

        if (pos <= mid) {
            updateTree(2 * nodeIdx + 1, nodeStart, mid, pos, val);
        } else {
            updateTree(2 * nodeIdx + 2, mid + 1, nodeEnd, pos, val);
        }
        tree[nodeIdx] = tree[2 * nodeIdx + 1] + tree[2 * nodeIdx + 2];
    }

    void lazyUpdateTree(int nodeIdx, int val, int queryStart, int queryEnd, int nodeStart, int nodeEnd) {
        int leftIndex = 2 * nodeIdx + 1;
        int rightIndex = 2 * nodeIdx + 2;

        if (lazy[nodeIdx] != 0) {
            tree[nodeIdx] += (nodeEnd - nodeStart + 1) * lazy[nodeIdx];

            if (nodeStart != nodeEnd) {  // not a leaf node
                lazy[leftIndex] += lazy[nodeIdx];
                lazy[rightIndex] += lazy[nodeIdx];
            }
            lazy[nodeIdx] = 0;
        }

        // If the current node range is completely outside the query range
        // qs----qe           qs------qe
        //          ns-----ne
        if (nodeStart > nodeEnd || nodeStart > queryEnd || nodeEnd < queryStart) {
            return;
        }

        // If the current node range is completely inside the query range
        // qs------------qe
        //     ns----ne
        if (nodeStart >= queryStart && nodeEnd <= queryEnd) {
            tree[nodeIdx] += (nodeEnd - nodeStart + 1) * val;

            if (nodeStart != nodeEnd) {
                lazy[leftIndex] += val;
                lazy[rightIndex] += val;
            }
            return;
        }

        int mid = (nodeStart + nodeEnd) / 2;
        lazyUpdateTree(leftIndex, val, queryStart, queryEnd, nodeStart, mid);
        lazyUpdateTree(rightIndex, val, queryStart, queryEnd, mid + 1, nodeEnd);
        tree[nodeIdx] = tree[leftIndex] + tree[rightIndex];
    }

    int queryTree(int nodeIdx, int queryStart, int queryEnd, int nodeStart, int nodeEnd) {
        //                 qs------------------qe
        //    ns-------ne                         ns------ne
        if (queryStart > nodeEnd || queryEnd < nodeStart) {
            return 0;
        }

        //                 qs------------------qe
        //                     ns-------ne
        if (queryStart <= nodeStart && queryEnd >= nodeEnd) {
            return tree[nodeIdx];
        }

        int mid = nodeStart + (nodeEnd - nodeStart) / 2;
        int leftSum = queryTree(2 * nodeIdx + 1, queryStart, queryEnd, nodeStart, mid);
        int rightSum = queryTree(2 * nodeIdx + 2, queryStart, queryEnd, mid + 1, nodeEnd);
        return leftSum + rightSum;
    }

   public:
    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val);
    }

    void updateRange(int queryStart, int queryEnd, int newValue) {
        lazyUpdateTree(0, newValue, queryStart, queryEnd, 0, n - 1);
    }

    int query(int queryStart, int queryEnd) {
        return queryTree(0, queryStart, queryEnd, 0, n - 1);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    SegmentTree segTree(nums);

    segTree.updateRange(0, 4, 10);
    // cout << segTree.query(0, 2) << endl;
    // segTree.update(0, 10);
    // cout << segTree.query(0, 2) << endl;

    for (auto& x : segTree.tree) {
        cout << x << ",";
    }
    cout << endl;

    return 0;
}