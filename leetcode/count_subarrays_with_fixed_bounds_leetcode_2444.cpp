#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int ans = 0;
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

int main() {
    vector<int> nums = {
        35054, 398719, 945315, 945315, 820417, 945315, 35054,
        945315, 171832, 945315, 35054, 109750, 790964, 441974, 552913};
    Solution sol;
    int ans = sol.countSubarrays(nums, 35054, 945315);

    cout << "ans: " << ans << endl;
}