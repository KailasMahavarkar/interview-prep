#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/last-stone-weight-ii/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : Problem is also called Minimum Difference Subset
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

class Solution {
   public:
    int t[31][5051];
    int minDiffSubset(vector<int>& stones, int n, int s1, int sum) {
        if (n == 0)
            return abs(sum - 2 * s1);

        if (t[n][s1] != -1)
            return t[n][s1];

        int take = minDiffSubset(stones, n - 1, s1 + stones[n - 1], sum);
        int dont_take = minDiffSubset(stones, n - 1, s1, sum);

        return t[n][s1] = min(take, dont_take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        memset(t, -1, sizeof(t));
        int sum = accumulate(begin(stones), end(stones), 0);
        int n = stones.size();
        return minDiffSubset(stones, n, 0, sum);
    }
};

int main() {
    vector<int> stones = {31, 26, 33, 21, 40};
    Solution sol;
    int ans = sol.lastStoneWeightII(stones);
    cout << "ans --> " << ans << endl;
}