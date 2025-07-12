#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/maximum-distance-in-arrays/description
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    int maxDistance(vector<vector<int>>& arrays) {
        int globalMinimum = INT_MAX;
        int globalMaximum = INT_MIN;

        int secondMinimum = INT_MAX - 1;
        int secondMaximum = INT_MIN + 1;

        for (auto& arr : arrays) {
            int s = 0;
            int e = arr.size() - 1;
        }

        return globalMaximum - globalMinimum;
    }
};

int main() {
    vector<vector<int>> arrays = {{1, 2, 3}, {4, 5}, {1, 2, 3}};

    Solution sol;
    int ans = sol.maxDistance(arrays);
    cout << "ans --> " << ans << endl;
}
