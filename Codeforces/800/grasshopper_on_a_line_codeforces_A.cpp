#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void solve(int x, int k) {
        // x -> final point
        // k -> grasshopper cannot jump on multiple of k's

        //                                                    x
        // |------------|-------------|------------|--------------|
        // k            2k            3k           4k             5k
        // if grasshopper is not on n*k step then 1 step is all we need
        if (x % k != 0) {
            cout << 1 << endl;
            cout << x << endl;
            return;
        }

        //                                                        x
        // |------------|-------------|------------|--------------|
        // k            2k            3k           4k             5k
        // we require 1 step to switch number line
        // but since we used 1 step now we are x - 1 distance away... so we will take 2nd step as x - 1
        // change number line ... from k to k+1 which is not k
        cout << 2 << endl;
        cout << x - 1 << " " << 1 << endl;
    }
};

int main() {
    int t;
    cin >> t;

    Solution sol;
    while (t--) {
        int x, k;
        cin >> x >> k;
        sol.solve(x, k);
    }

    // Solution sol;
    // vector<vector<int>> ops = {
    //     {10, 2},
    //     // {10, 3},
    //     // {3, 4},
    // };

    // for (int i = 0; i < ops.size(); i++) {
    //     sol.solve(ops[i][0], ops[i][1]);
    // }

    return 0;
}
