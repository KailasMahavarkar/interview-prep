#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Method 1: top-down
class SolutionMemo {
   public:
    vector<int> dp;
    int solve(vector<int>& nums, int idx, int n) {
        if (idx > n) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int rob_house = nums[idx] + solve(nums, idx + 2, n);
        int dont_rob_house = solve(nums, idx + 1, n);
        return dp[idx] = max(rob_house, dont_rob_house);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        dp.resize(n + 1, -1);
        int take_0th_house = solve(nums, 0, n - 2);

        dp.assign(n + 1, -1);
        int dont_take_0th_house = solve(nums, 1, n - 1);

        return max(take_0th_house, dont_take_0th_house);
    }
};

// Method2: bottom up
class SolutionBottomUp {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> t(n + 1, 0);

        t[0] = 0;

        // case 1: we take 1st house we cannot take last house
        // starting index = 1
        // ending index = 2nd last house (since if we take 1st house we cant take last house)
        for (int i = 1; i <= n - 1; i++) {
            int take = (i - 2 >= 0 ? t[i - 2] : 0) + nums[i - 1];
            int skip = t[i - 1];
            t[i] = max(skip, take);
        }

        // case 2: we dont take 1st house, we can take last house
        // we cant take 1st house so we took next house which was at 2nd position
        // starting index = 2
        // ending index = last house
        int result1 = t[n - 1];

        t.assign(n + 1, -1);
        t[0] = 0;
        t[1] = 0;

        for (int i = 2; i <= n; i++) {
            int take = (i - 2 >= 0 ? t[i - 2] : 0) + nums[i - 1];
            int skip = t[i - 1];
            t[i] = max(skip, take);
        }

        int result2 = t[n];
        return max(result1, result2);
    }
};

// Method 3: bottomup - space optimized
class SolutionBottomUpSpaceOptimized {
   public:
    int solve(vector<int>& nums, int l, int r) {
        int prev = 0;
        int prevPrev = 0;
        for (int i = l; i <= r; i++) {
            int skip = prev;
            int take = (i - 2 >= 0 ? prevPrev : 0) + nums[i];
            int temp = max(skip, take);
            prevPrev = prev;
            prev = temp;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        int take_1st_house = solve(nums, 1, n - 1);
        int dont_take_1st_house = solve(nums, 2, n);

        return max(take_1st_house, dont_take_1st_house);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    SolutionBottomUp s;
    cout << s.rob(nums) << endl;
    return 0;
}
