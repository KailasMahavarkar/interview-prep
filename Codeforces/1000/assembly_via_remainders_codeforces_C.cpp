#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<int> findArray(vector<int>& x) {
        int max_x = *max_element(x.begin(), x.end());
        vector<int> a;
        a.push_back(max_x + 1);
        for (int xi : x) {
            a.push_back(a.back() + xi);
        }
        return a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            cin >> x[i];
        }
        Solution sol;
        vector<int> a = sol.findArray(x);
        for (int num : a) {
            cout << num << " ";
        }
        cout << endl;
    }

    // vector<int> arr = {4, 2, 5, 1, 2};
    // Solution sol;
    // vector<int> ans = sol.findArray(arr);
    // for (auto& x : ans) {
    //     cout << x << " ";
    // }
    // cout << endl;

    return 0;
}
