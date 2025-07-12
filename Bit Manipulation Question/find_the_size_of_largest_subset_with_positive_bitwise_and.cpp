#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : None
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Bitwise AND + count)
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    int largestBitwiseSubset(vector<int> &arr) {
        int globalMax = 0;

        for (int i = 0; i < 32; i++) {
            int localMax = 0;

            for (auto &x : arr) {
                bitset<32> bs(x);
                localMax += bs[i];
            }

            globalMax = max(localMax, globalMax);
        }

        return globalMax;
    }
};

int main() {
    vector<int> arr = {7, 13, 8, 2, 3};
    Solution sol;
    int ans = sol.largestBitwiseSubset(arr);
    cout << ans;
}


// 7 -->  00111
// 13 --> 01101
//  8 --> 01000
//  2 --> 00010
//  3 --> 00011
//        ------
//        02233
// we can form {7,13,3} or {7,2,3} which has length of 3