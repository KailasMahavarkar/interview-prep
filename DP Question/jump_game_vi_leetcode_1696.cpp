#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/jump-game-vi/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class SolutionMemo {
   public:
    int K;
    int n;
    unordered_map<int, int> dp;
    int solve(vector<int>& nums, int idx) {
        if (idx == n - 1) {
            return nums[idx];
        }

        if (dp.find(idx) != dp.end()) {
            return dp[idx];
        }

        int result = INT_MIN;
        for (int i = idx + 1; i <= min(n - 1, idx + K); i++) {
            result = max(result, solve(nums, i));
        }
        return dp[idx] = nums[idx] + result;
    }

    int maxResult(vector<int>& nums, int k) {
        K = k;
        n = nums.size();
        return solve(nums, 0);
    }
};

typedef pair<int, int> P;
class Solution {
   public:
    struct comparator {
        bool operator()(P& p1, P& p2) {
            return p1.first < p2.first;
        }
    };
    int maxResult(vector<int>& nums, int k) {
        priority_queue<P, vector<P>, comparator> pq;

        int n = nums.size();
        pq.push({nums[0], 0});
        for (int i = 1; i < n; i++) {
            while (i - k > pq.top().second) {
                pq.pop();
            }

            pq.push({nums[i] + pq.top().first, i});
        }

        // we have to return the score we have got at index n-1
        while (!pq.empty() && pq.top().second != n - 1)
            pq.pop();

        return pq.top().first;
    }
};

int main() {
    vector<int> nums = {1, -1, -2, 4, -7, 3};
    int k = 2;
    Solution sol;
    int ans = sol.maxResult(nums, k);
    cout << "ans --> " << ans << endl;
}