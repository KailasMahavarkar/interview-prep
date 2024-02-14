#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
   public:
    vector<int> st;
    int n;

    int constructSt(vector<int>& nums, int l, int r, int si) {
        if (l > r)
            return 0;
        if (l == r) {
            st[si] = nums[l];
            return st[si];
        }
        int mid = l + (r - l) / 2;

        st[si] = constructSt(nums, l, mid, 2 * si + 1) + constructSt(nums, mid + 1, r, 2 * si + 2);

        return st[si];
    }

    int getSum(int ss, int se, int qs, int qe, int si) {
        if (ss >= qs && se <= qe)
            return st[si];

        if (se < qs || ss > qe)
            return 0;

        int mid = ss + (se - ss) / 2;

        return getSum(ss, mid, qs, qe, 2 * si + 1) + getSum(mid + 1, se, qs, qe, 2 * si + 2);
    }

    void updateSt(int ss, int se, int idx, int diff, int si) {
        if (idx < ss || idx > se)
            return;

        st[si] += diff;

        if (ss != se) {
            int mid = ss + (se - ss) / 2;
            updateSt(ss, mid, idx, diff, 2 * si + 1);
            updateSt(mid + 1, se, idx, diff, 2 * si + 2);
        }
    }

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        int seg_size = 4 * n;
        st.resize(seg_size);
        int si = 0;
        constructSt(nums, 0, n - 1, si);
    }

    int getSum(int qs, int qe) {
        return getSum(0, n - 1, qs, qe, 0);
    }

    void update(int idx, int val) {
        int diff = val - st[idx];
        updateSt(0, n - 1, idx, diff, 0);
    }
};

int main() {
    vector<int> nums{1, 3, 5};
    SegmentTree segTree(nums);

    // This is my segment tree
    for (int i = 0; i < 4 * nums.size(); i++) {
        cout << segTree.st[i] << " ";
    }
    cout << endl;

    // Range queries (O(log(n))
    cout << segTree.getSum(0, 1) << endl;  // output : 4
    cout << segTree.getSum(1, 2) << endl;  // output : 8

    // Update array
    int idx = 1;
    int val = 4;

    // Update value
    segTree.update(idx, val);

    // Range queries (O(log(n))
    cout << segTree.getSum(0, 1) << endl;  // output : 4
    cout << segTree.getSum(1, 2) << endl;  // output : 8

    return 0;
}
