#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/
    Company Tags   : None
    Youtube Link   : https://youtu.be/06VaWkj8e-0?t=213
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(), nums.end());

        int l = 0;
        int r = 0;
        int n = nums.size();
        int count = 0;

        long long answer = 0;

        while (r < n) {
            if (nums[r] == max) {
                count++;
            }

            while (count >= k) {
                if (nums[l] == max) {
                    count--;
                }
                l++;
                answer += (n - r);
            }

            r++;
        }

        return answer;
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    Solution sol;
    long long ans = sol.countSubarrays(nums, k);
    cout << "ans --> " << ans << endl;
}