#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(vector<int>& a) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;

        for (int num : a) {
            if (num % 3 == 0) {
                c0++;
            } else if (num % 3 == 1) {
                c1++;
            } else {
                c2++;
            }
        }

        vector<int> count = {c0, c1, c2};
        int target = (c0 + c1 + c2) / 3;
        int moves = 0;

        for (int _ = 0; _ < 3; _++) {
            for (int i = 0; i < 3; i++) {
                if (count[i] > target) {
                    int surplus = count[i] - target;
                    count[i] -= surplus;
                    count[(i + 1) % 3] += surplus;
                    moves += surplus;
                }
            }
        }

        cout << moves << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution sol;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sol.solve(a);
    }

    // vector<int> arr = {0, 2, 5, 5, 4, 8};
    // sol.solve(arr);

    return 0;
}
