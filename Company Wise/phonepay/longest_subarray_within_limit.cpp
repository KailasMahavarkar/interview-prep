#include <bits/stdc++.h>
using namespace std;
// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.
// Looking at the examples:
// Input: nums = [8,2,4,7], limit = 4 → Output: 2
// Input: nums = [10,1,2,4,7,2], limit = 5 → Output: 4

class Solution {
   public:
    int solve(vector<int> &nums, int limit) {
        int n = nums.size();
        deque<int> maxDeque;  // decreasing
        deque<int> minDeque;  // increasing

        int left = 0;
        int result = 0;

        for (int right = 0; right < n; ++right) {
            // Maintain decreasing maxDeque
            while (!maxDeque.empty() && nums[right] > maxDeque.back()) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);

            // Maintain increasing minDeque
            while (!minDeque.empty() && nums[right] < minDeque.back()) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);

            // Shrink window if invalid
            while (!maxDeque.empty() && !minDeque.empty() &&
                   maxDeque.front() - minDeque.front() > limit) {
                if (nums[left] == maxDeque.front()) maxDeque.pop_front();
                if (nums[left] == minDeque.front()) minDeque.pop_front();
                ++left;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {10, 1, 2, 4, 7, 2};
    int limit = 5;
    Solution sol;
    int ans = sol.solve(nums, limit);
    cout << "ans --> " << ans << endl;
}