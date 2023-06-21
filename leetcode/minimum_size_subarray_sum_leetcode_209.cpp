#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int ans = INT_MAX;

        int i = 0, j = 0, n = nums.size();

        while (j < n) {
            while (sum < target && j < n) {
                sum += nums[j++];
            }
            while (sum >= target) {
                ans = min(j - i, ans);
                sum -= nums[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int ans = sol.minSubArrayLen(7, nums);
    cout << "ans -->" << ans;
}