#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/container-with-most-water/description/
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
    int maxArea(vector<int>& H) {
        int s = 0;
        int e = H.size() - 1;
        int maxArea = 0;
        while (s < e) {
            // Why take min????
            // because water cannot flow to higher pipe
            // i mean if you were to form a rect container that respects gravity
            // then water can maximum fill to lower height and never higher
            maxArea = max(maxArea, (e - s) * min({H[e], H[s]}));
            if (H[s] <= H[e]) {
                s++;
            } else {
                e--;
            }
        }

        return maxArea;
    }
};

int main() {
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    int ans = sol.maxArea(nums);
    cout << "ans --> " << ans << endl;
}
