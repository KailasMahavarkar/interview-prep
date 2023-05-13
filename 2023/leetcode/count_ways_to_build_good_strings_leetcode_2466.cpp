#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int low, zero, one, high;
    int MOD = 1e9 + 7;
    int solve(int len) {
        // we dont consider string with more than high length
        if (len > high) {
            return 0;
        }

        // check current string length
        bool addCurrent = false;

        if (len >= low && len <= high) {
            addCurrent = true;
        }

        // append zero
        int appendZero = solve(len + zero);

        // append one
        int appendOne = solve(len + one);

        return (addCurrent + appendZero + appendOne) % MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        this->low = low;
        this->high = high;
        this->zero = zero;
        this->one = one;

        return solve(0);
    }
};

int main() {
    Solution sol;
    int low = 3;
    int high = 3;
    int zero = 1;
    int one = 1;

    sol.countGoodStrings(low, high, zero, one);
}