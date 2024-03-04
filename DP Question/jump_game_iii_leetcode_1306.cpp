#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/jump-game-iii/
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
    int n;
    vector<int> dp;
    bool solve(vector<int>& arr, int idx) {
        if (idx < 0 || idx >= n || arr[idx] == -1) {
            return false;
        }

        if (arr[idx] == 0) {
            return true;
        }

        // we are marking it as -1.. to avoid endless recursive calls... since arr[idx]
        // arr = [3, 2, 1, 0, 4] .. idx = 4
        // when recursion roll back value of solve will always be
        // solve(arr, idx + 4) -> solve(arr, 8)
        // goes out of bound -> but recursion roll back ... calling solve(idx + jump) & solve(idx - jump)
        // since we can go [idx - jump]... we will run into infinite loop to avoid it we simply mark arr[idx] as -1
        int jump = arr[idx];
        arr[idx] = -1;

        return solve(arr, idx + jump) || solve(arr, idx - jump);
    }

    bool canReach(vector<int>& arr, int idx) {
        n = (int)arr.size();
        return solve(arr, idx);
    }
};

int main() {
    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    Solution sol;
    cout << "ans -->" << sol.canReach(arr, 5) << endl;
}