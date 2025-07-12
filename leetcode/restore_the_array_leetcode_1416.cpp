#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
class Solution {
   public:
    int n;

    const int MOD = 1e9 + 7;
    vector<int> dp;

    int solve(int idx, string &s, int &k) {
        if (idx >= n)
            return 1;

        if (dp[idx] != -1)
            return dp[idx];

        if (s[idx] == '0')
            return dp[idx] = 0;

        long ans = 0;
        long long num = 0;

        for (int end = idx; end < n; end++) {
            num = (num * 10) + (s[end] - '0');
            if (num > k)
                break;

            ans = (ans % MOD + solve(end + 1, s, k) % MOD) % MOD;
        }

        return dp[idx] = ans;
    }

    int numberOfArrays(string s, int k) {
        n = s.length();
        dp.resize(n, -1);
        return solve(0, s, k, t);
    }
};

int main() {
}