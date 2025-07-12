#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/constrained-subsequence-sum/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal -> TLE)
// TC : O(2^N)
// SC : O(1)
class SolutionBruteForce {
   public:
    int K;
    int n;
    int solve(vector<int> nums, int prev, int idx) {
        if (idx >= n) {
            return 0;
        }

        int maxPossible = 0;
        if (prev == -1 || idx - prev <= K) {
            int take = nums[idx] + solve(nums, idx, idx + 1);
            int dont_take = solve(nums, prev, idx + 1);
            maxPossible = max(take, dont_take);
        }

        return maxPossible;
    }

    int constrainedSubsetSum(vector<int>& nums, int k) {
        K = k;
        n = nums.size();
        int possibleAnswer = solve(nums, -1, 0);
        if (possibleAnswer == 0) {
            possibleAnswer = *max_element(nums.begin(), nums.end());
        }

        return possibleAnswer;
    }
};

// Approach-2 (Recursion + Memo)
// TC: O(N^2)
// SC: O(N^2)
class SolutionMemo {
   public:
    int K;
    int n;
    unordered_map<string, int> hmap;
    int solve(vector<int> nums, int prev, int idx) {
        string key = to_string(prev) + "_" + to_string(idx);

        if (hmap.find(key) != hmap.end()) {
            return hmap[key];
        }

        if (idx >= n) {
            return 0;
        }

        int maxPossible = 0;
        if (prev == -1 || idx - prev <= K) {
            // take
            int take = nums[idx] + solve(nums, idx, idx + 1);
            int dont_take = solve(nums, prev, idx + 1);
            maxPossible = max(take, dont_take);
        }

        return hmap[key] = maxPossible;
    }

    int constrainedSubsetSum(vector<int>& nums, int k) {
        K = k;
        n = nums.size();
        int possibleAnswer = solve(nums, -1, 0);
        if (possibleAnswer == 0) {
            possibleAnswer = *max_element(nums.begin(), nums.end());
        }

        return possibleAnswer;
    }
};

// Approach-3 (Bottom up)
// TC: O(N^2)
// SC: O(N)
class SolutionBottomUp {
   public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i];
        }

        int result = dp[0];

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0 && i - j <= k; j--) {
                dp[i] = max(dp[i], nums[i] + dp[j]);
                result = max(result, dp[i]);
            }
        }

        return result;
    }
};

// Approach-4 (Bottom up with heap)
// TC: O(nlogn)
// SC: O(n)
class Solution {
   public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp = nums;

        int result = dp[0];

        priority_queue<pair<int, int>> pq;
        pq.push({dp[0], 0});

        for (int i = 1; i < n; i++) {
            // think "pq.top().second" as j
            while (!pq.empty() && i - pq.top().second > k) {
                pq.pop();
            }

            dp[i] = max(dp[i], nums[i] + pq.top().first);
            pq.push({dp[i], i});
            result = max(dp[i], result);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {10, 2, -10, 5, 20};

    Solution sol;
    int ans = sol.constrainedSubsetSum(nums, 2);

    cout << ans << endl;
}
