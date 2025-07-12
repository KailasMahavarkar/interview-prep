#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Verdict:
// This Questions is Insane Difficulty, Skip it (waste of time)

class Solution {
   public:
    void solve(vector<int> &arr, int n) {
        int x = 0;
        for (int i = 1; i <= n; i++) {
            x += arr[i];
        }
        cout << arr[n] - (arr[n - 1] - (x - arr[n] - arr[n - 1])) << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        sol.solve(arr, n);
    }

    return 0;
}
