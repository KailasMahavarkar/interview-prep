#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
   public:
    vector<int> tree;
    vector<int> nums;
    int n;

    SegmentTree(vector<int>& input) {
        n = input.size();
        nums = input;
        tree.resize(4 * n, 0);
        buildTree(0, 0, n - 1);
    }

   private:
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

    void updateTree(int pos, int val, int l, int r, int idx) {
        if (l == r) {
            tree[idx] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            updateTree(pos, val, l, mid, 2 * idx + 1);
        } else {
            updateTree(pos, val, mid + 1, r, 2 * idx + 2);
        }

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int queryTree(int idx, int l, int r, int s, int e) {
        // Actual query is (s, e)
        // l -> current left where l is lying
        // r -> current right where r is lying

        // Case 1: Out of bounds (no overlap)
        if (l > e || r < s) {
            return 0;
        }

        // Case 2: Completely within range
        if (l >= s && r <= e) {
            return tree[idx];
        }

        // Case 3: Overlapping range
        int mid = l + (r - l) / 2;
        int leftQuery = queryTree(2 * idx + 1, l, mid, s, e);
        int rightQuery = queryTree(2 * idx + 2, mid + 1, r, s, e);
        return leftQuery + rightQuery;
    }

   public:
    void update(int pos, int val) {
        updateTree(pos, val, 0, n - 1, 0);
    }

    int query(int s, int e) {
        return queryTree(0, 0, n - 1, s, e);
    }
};

int main() {
    vector<int> input = {1, 2, 3, 4};
    SegmentTree segTree(input);
    cout << "Initial range sum [0, 3]: " << segTree.query(0, 3) << endl;
    segTree.update(0, 11);
    cout << "Updated range sum [0, 3]: " << segTree.query(0, 3) << endl;

    for (auto& x : segTree.tree) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
