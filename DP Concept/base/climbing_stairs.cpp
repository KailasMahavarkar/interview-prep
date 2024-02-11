#include <bits/stdc++.h>
using namespace std;

// Method 1: top-down
class SolutionTopDown {
   public:
    vector<int> dp;

    int solve(int n) {
        // base case for failure
        if (n < 0) {
            return 0;
        }

        // base case for success
        if (n == 0) {
            return 1;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int one_step = solve(n - 1);
        int two_step = solve(n - 2);

        return dp[n] = one_step + two_step;
    }

    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return solve(n);
    }
};

// Method 2 : bottom up
class SolutionBottomUp {
   public:
    int climbStairs(int n) {
        vector<int> t(n + 1, 0);
        t[0] = 1;
        t[1] = 1;
        for (int i = 2; i <= n; i++) {
            t[i] = t[i - 1] + t[i - 2];
        }
        return t[n];
    }
};

// Method 2: bottom up (optimized)
class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) {
            return n;
        }

        int a = 1;
        int b = 1;
        int c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(10) << endl;
    return 0;
}