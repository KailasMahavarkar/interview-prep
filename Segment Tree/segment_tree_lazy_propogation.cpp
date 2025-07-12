#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class SegmentTree {
   public:
    int n;
    vector<int> tree;
    vector<int> lazy;

    SegmentTree(vector<int> &input) {
        int size = input.size();
        n = size;
        tree.resize(4 * size, 0);
        lazy.resize(4 * size, 0);
        buildTree(input, 0, size - 1, 0);
    }

   private:
    void buildTree(vector<int> &nums, int l, int r, int idx) {
        if (l == r) {
            tree[idx] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        buildTree(nums, l, mid, idx * 2 + 1);
        buildTree(nums, mid + 1, r, idx * 2 + 2);
        tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
    }

    int queryTree(int queryStart, int queryEnd, int nodeStart, int nodeEnd, int idx) {
        //            qs---------qe
        // ns----ne                    ns-------ne
        if (queryStart > nodeEnd || queryEnd < nodeStart) {
            return 0;
        }

        //            qs-----------qe
        //                ns----ne
        if (queryStart <= nodeStart && queryEnd >= nodeEnd) {
            return tree[idx];
        }

        int mid = nodeStart + (nodeEnd - nodeStart) / 2;
        int leftSum = queryTree(queryStart, queryEnd, nodeStart, mid, idx * 2 + 1);
        int rightSum = queryTree(queryStart, queryEnd, mid + 1, nodeEnd, idx * 2 + 2);
        return leftSum + rightSum;
    }

    void updateTree(int position, int value, int nodeStart, int nodeEnd, int idx) {
        if (nodeStart == nodeEnd) {
            tree[idx] = value;
            return;
        }

        int mid = nodeStart + (nodeEnd - nodeStart) / 2;
        if (position <= mid) {
            updateTree(position, value, nodeStart, mid, idx * 2 + 1);
        } else {
            updateTree(position, value, mid + 1, nodeEnd, idx * 2 + 2);
        }
        tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
    }

    // lazy propogation
    void updateRangeTree(int queryStart, int queryEnd, int nodeStart, int nodeEnd, int value, int idx) {
        int leftIndex = 2 * idx + 1;
        int rightIndex = 2 * idx + 2;

        // update previous lazy values
        if (lazy[idx] != 0) {
            tree[idx] = (nodeEnd - nodeStart + 1) * lazy[idx]; // TODO: why do we need this? 
            // if node is not a leaf node
            if (nodeStart != nodeEnd) {
                lazy[leftIndex] += lazy[idx];
                lazy[rightIndex] += lazy[idx];
            }
            lazy[idx] = 0;  // clear previous lazy value
        }

        // validate lazy query range
        //                  qs---------qe
        //   ns----------ne               ns--------ne
        if (nodeStart > nodeEnd || queryStart > nodeEnd || queryEnd < nodeStart) {
            return;
        }

        // contains completely -> perform lazy propogation
        //                  qs---------qe
        //                     ns---ne
        if (nodeStart >= queryStart && nodeEnd <= queryEnd) {
            tree[idx] += (nodeEnd - nodeStart + 1) * value;
            if (nodeStart != nodeEnd) {
                lazy[leftIndex] += value;
                lazy[rightIndex] += value;
                return;
            }
        }

        int mid = nodeStart + (nodeEnd - nodeStart) / 2;
        updateRangeTree(queryStart, queryEnd, nodeStart, mid, value, leftIndex);
        updateRangeTree(queryStart, queryEnd, mid + 1, nodeEnd, value, rightIndex);
        tree[idx] = tree[leftIndex] + tree[rightIndex];
    }

   public:
    int query(int queryStart, int queryEnd) {
        return queryTree(queryStart, queryEnd, 0, n - 1, 0);
    }

    void update(int pos, int val) {
        updateTree(pos, val, 0, n - 1, 0);
    }

    void updateRange(int queryStart, int queryEnd, int value) {
        updateRangeTree(queryStart, queryEnd, 0, n - 1, value, 0);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    SegmentTree segTree(nums);

    segTree.updateRange(0, 4, 10);
    cout << "query: " << segTree.query(0, 4) << endl;

    for (auto &x : segTree.tree) {
        cout << x << " ";
    }
    cout << endl;
}