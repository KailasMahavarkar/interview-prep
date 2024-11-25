#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/search-insert-position/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (BruteForce)
// TC : O(1)
// SC : O(n)
class SolutionBruteForce {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }

        return n;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 0;
    SolutionBruteForce sol;
    cout << "ans -->" << sol.searchInsert(nums, target) << endl;
}
