#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/
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
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> ans(n, vector<int>(0, 0));

        for (auto pairr : edges) {
            int ancestor = pairr[0];
            int current = pairr[1];
            ans[current].push_back(ancestor);
        }

        // for (vector<int> arr : ans) {
        //     sort(arr.begin(), arr.end());
        // }

        return ans;
    }
};

int main() {
    vector<vector<int>> arr = {{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};

    Solution sol;
    vector<vector<int>> ans = sol.getAncestors(arr.size(), arr);

    for (auto &v : ans) {
        for (auto &x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}