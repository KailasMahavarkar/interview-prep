#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

class SegmentTree {
   public:
    vector<int> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void updateTree(int idx, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] += value;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            updateTree(idx, value, 2 * node + 1, start, mid);
        } else {
            updateTree(idx, value, 2 * node + 2, mid + 1, end);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int queryTree(int qs, int qe, int node, int start, int end) {
        if (qs > end || qe < start) {
            return 0;
        }
        if (qs <= start && qe >= end) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int left = queryTree(qs, qe, 2 * node + 1, start, mid);
        int right = queryTree(qs, qe, 2 * node + 2, mid + 1, end);
        return left + right;
    }

    void update(int idx, int value) {
        updateTree(idx, value, 0, 0, n - 1);
    }

    int query(int qs, int qe) {
        return queryTree(qs, qe, 0, 0, n - 1);
    }
};

vector<int> countSmaller(vector<int>& nums) {
    set<int> sortedSet(nums.begin(), nums.end());
    unordered_map<int, int> rank;
    int idx = 0;
    for (int num : sortedSet) {
        rank[num] = idx++;
    }

    SegmentTree segTree(rank.size());
    vector<int> result(nums.size());

    for (int i = nums.size() - 1; i >= 0; --i) {
        int compressedIdx = rank[nums[i]];
        result[i] = segTree.query(0, compressedIdx - 1);
        segTree.update(compressedIdx, 1);
    }

    for (auto& x : segTree.tree) {
        cout << x << "";
    }
    cout << endl;

    return result;
}

int main() {
    vector<int> nums = {5, 6, 3, 1, 2};
    vector<int> result = countSmaller(nums);

    for (auto& x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
