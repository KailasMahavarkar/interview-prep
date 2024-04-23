#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://www.geeksforgeeks.org/problems/cutted-segments1642/1
    Company Tags   : Amazon, Microsoft, OYO Rooms
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : Rod Cutting Problem
*/

// Approach-1 (Normal)
// TC : O(N)
// SC : O(N)
class Solution {
   public:
    vector<int> dp;
    int solve(int n, int x, int y, int z) {
        if (n == 0)
            return 0;
        if (n < 0)
            return INT_MIN;

        if (dp[n] != -1)
            return dp[n];

        int cut_x = 1 + solve(n - x, x, y, z);
        int cut_y = 1 + solve(n - y, x, y, z);
        int cut_z = 1 + solve(n - z, x, y, z);

        // Taking maximum cuts after making a cut of length x, y, or z.
        return dp[n] = max({cut_x, cut_y, cut_z});
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        dp.resize(n + 1, -1);
        int result = solve(n, x, y, z);
        return result < 0 ? 0 : result;
    }
};

int main() {
    Solution sol;
    int N = 4, x = 2, y = 1, z = 1;
    int ans = sol.maximizeTheCuts(N, x, y, z);
    cout << "ans --> " << ans << endl;
}