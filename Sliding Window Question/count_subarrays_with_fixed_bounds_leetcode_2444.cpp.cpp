#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minPos = -1;
        int maxPos = -1;
        int culprit_index = -1;

        
        for (int i = 0; i < nums.size(); i++) {
            if (minK == nums[i]) {
                minPos = i;
            }
            if (maxK == nums[i]) {
                maxPos = i;
            }

            if (nums[i] < minK || nums[i] > maxK) {
                culprit_index = i;
            }

            long long smaller = min(minPos, maxPos);
            long long temp = smaller - culprit_index;

            if (temp > 0) {
                ans += temp;
            }
        }

        return ans;
    }
};


/*
    mi = minK
    mx = maxK
    ci = culprit_index
    cond1 = nums[i] < minK || nums[i] > maxK


    &) dry run on -> 7 1 2 4 6 1 4    

    iteration 1: 
    7  1  2  4  6  1  4
    i

    before:
    mi = -1
    mx = -1
    ci = -1

    -> (7 < 1 || 7 > 5) -> fails -> ci = 0
    smaller = min(-1, -1)
    temp = -1 - ci -> -1 - 0 = -1
    since temp > 0 -> we dont add to result

    mi = -1
    mx = -1
    ci = 0

    iteration 2: 
    7  1  2  4  6  1  4
       i

    mi = 1
    mx = -1
    ci = 0

    -> (1 < 1 || 1 > 5) -> passes -> ci = 0
    smaller = min(1, -1)
    temp = -1 - ci -> -1 - 0 = -1
    since temp > 0 -> we dont add to result -> offcourse we cant cuz we didnt find maxK yet

    iteration 3: 
    7  1  2  4  6  1  4
          i

    mi = 1
    mx = -1
    ci = 0

    -> (2 < 1 || 2 > 5) -> passes -> ci = 0
    smaller = min(2, -1)
    temp = -1 - ci -> -1 - 0 = -1
    since temp > 0 -> we dont add to result -> offcourse we cant cuz we didnt find maxK yet

    iteration 4: 
    7  1  2  4  6  1  4
             i

    mi = 1
    mx = 4
    ci = 0

    -> (4 < 1 || 4 > 5) -> passes -> ci = 0
    smaller = min(1, 4)
    temp = 1 - ci -> 1 - 0 = 1
    since temp > 0 -> we add 1 to result -> after ci we found one subarray [1, 2, 4] which satisfied the condition

    iteration 5: 
    7  1  2  4  6  1  4
                i

    mi = 1
    mx = 4
    ci = 0

    -> (6 < 1 || 6 > 5) -> fails -> ci = 4
    smaller = min(1, 4)
    temp = 1 - ci -> 1 - 4 = -3
    since temp > 0 -> since temp is -ve

    iteration 6: 
    7  1  2  4  6  1  4
                   i

    mi = 5
    mx = 4
    ci = 4

    -> (1 < 1 || 1 > 5) -> fails -> ci = 4
    smaller = min(5, 4)
    temp = 4 - 4 -> 0
    since temp > 0 -> false

    iteration 7: 
    7  1  2  4  6  1  4
                      i

    mi = 5
    mx = 6
    ci = 4

    -> (4 < 1 || 4 > 5) -> fails -> ci = 4
    smaller = min(5, 6)
    temp = 5 - 4 -> 1
    since temp > 0 -> we add 1 to result -> after ci we found one subarray [1, 4] which satisfied the condition

    Answer = 2
*/ 



int main() {
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    Solution sol;
    long long ans = sol.maxLen(nums, k);
    cout << "ans --> " << ans << endl;
}