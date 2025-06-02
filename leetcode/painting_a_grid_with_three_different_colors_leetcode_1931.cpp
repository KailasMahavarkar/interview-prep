#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Name   : None
    Problem Link   : https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/
class Solution {
   public:
    int m, n;
    int MOD = 1e9 + 7;
    vector<int> validMasks;
    unordered_map<short, vector<short>> compatible;

    void generateValidMasks(int row = 0, int mask = 0, int prevColor = -1) {
        if (row == m) {
            validMasks.push_back(mask);  // push single int mask directly
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (color != prevColor) {
                generateValidMasks(row + 1, mask * 3 + color, color);
            }
        }
    }

    // check if two column masks are compatible (no row has same color)
    bool isCompatible(int a, int b) {
        for (int i = 0; i < m; ++i) {
            int ca = a % 3;
            int cb = b % 3;
            if (ca == cb) return false;
            a /= 3;
            b /= 3;
        }
        return true;
    }

    int colorTheGrid(int M, int N) {
        m = M;
        n = N;

        generateValidMasks();

        // Build compatible mask mapping
        for (int mask1 : validMasks) {
            for (int mask2 : validMasks) {
                if (isCompatible(mask1, mask2)) {
                    compatible[mask1].push_back(mask2);
                }
            }
        }


        // why is temp needed? simple hai... so we dont modify the DP while iterating
        unordered_map<int, int> dp, temp;


        // column 1 se answer lana always possible h
        for (int mask : validMasks) {
            dp[mask] = 1;
        }

        // DP column by column
        for (int col = 1; col < n; ++col) {
            for (auto& x : dp) {
                int currMask = x.first;
                int currCount = x.second;
                for (int nextMask : compatible[currMask]) {
                    temp[nextMask] = (temp[nextMask] + currCount) % MOD;
                }
            }
            swap(dp, temp) // its simply means dp = temp
            temp.clear();
        }

        int res = 0;
        for (auto& [mask, count] : dp) {
            res = (res + count) % MOD;
        }

        return res;
    }
};

int main() {
    Solution obj;
    int m = 5, n = 5;
    cout << obj.colorTheGrid(m, n) << endl;
    return 0;
}