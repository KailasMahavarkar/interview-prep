#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

// [ 3, 2, 3, 2 ]
// +-----+------+-----------+
// |  i  | a[i] | i - a[i]  |
// +-----+------+-----------+
// |  0  |  3   |   -3      |
// |  1  |  2   |   -1      |
// |  2  |  3   |   -1      | <- fails since -1 is repeating but it was unique right?
// |  3  |  2   |    1      |
// +-----+------+-----------+

// +-----+------+-----------+
// |  i  | a[i] | i - a[i]  |
// +-----+------+-----------+
// |  0  |  3   |   -3      |
// |  1  |  3   |   -2      |
// |  2  |  2   |    0      |
// |  3  |  2   |    1      | 
// +-----+------+-----------+ <- all offsets are unique this passes

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solve(vector<int>& a) {
        sort(a.rbegin(), a.rend());

        for (auto& x : a) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        Solution sol;
        sol.solve(a);
    }

    return 0;
}
