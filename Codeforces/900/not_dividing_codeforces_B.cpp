#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Concept:
// why this works?
// Divisibility TODNE ke liye maximum 1 operation hi lagega between any pairs (factors)

class Solution {
   public:
    void solve(vector<int> &arr) {
        int n = arr.size();

        // one can divide any number... have to avoid it
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) arr[i]++;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (arr[i + 1] % arr[i] == 0) {  // so if arr[i] is factor of arr[i+1]... we break that logic
                arr[i + 1]++;
            }
        }

        for (auto &x : arr) {
            cout << x << " ";
        }
    }
};

int main() {
    int t;
    cin >> t;

    Solution sol;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sol.solve(a);
    }

    // vector<int> arr = {2, 4, 3, 6};
    // Solution sol;
    // sol.solve(arr);

    return 0;
}
