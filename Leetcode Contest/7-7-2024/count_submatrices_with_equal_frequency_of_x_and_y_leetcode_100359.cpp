#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/contest/weekly-contest-405/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/
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
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        return -1;
    }
};

int main() {
    vector<vector<char>> grid = {{'X', 'Y', '.'}, {'Y', '.', '.'}}; // outputs: 3
    Solution sol;
    int ans = sol.numberOfSubmatrices(grid);
    cout << "ans --> " << ans << endl;
}