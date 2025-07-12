#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int n) {
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        for (int i = 0; i + 1 < n; i += 2) {
            swap(arr[i], arr[i + 1]);
        }

        // if nums is odd swap 1st and last
        if (n % 2 == 1) {
            swap(arr[0], arr[n - 1]);
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] + 1 << " ";
        }
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution sol;
        sol.solve(n);
    }

    // Solution sol;
    // sol.solve(5);
    return 0;
}
