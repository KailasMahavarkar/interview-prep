#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(int n, vector<int>& b) {
        sort(b.begin(), b.end());
        long long total_sum = accumulate(b.begin(), b.end(), 0LL);

        for (int i = 0; i < 2 * n; i++) {
            long long possible_missing = b[i];
            long long remaining_sum = total_sum - possible_missing;
        }

        cout << "No valid sequence found\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while (t--) {
    //     int n;
    //     cin >> n;
    //     vector<int> b(2 * n);
    //     for (int i = 0; i < 2 * n; i++) {
    //         cin >> b[i];
    //     }

    //     Solution().solve(n, b);
    // }

    vector<int> b = {99, 2, 86, 33, 14, 77};

    Solution sol;
    sol.solve(3, b);

    return 0;
}
