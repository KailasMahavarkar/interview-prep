#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class SolutionMemo {
   public:
    vector<int> dp;
    int solve(vector<int>& nums, int idx) {
        if (idx > nums.size()) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int rob_house = nums[idx] + solve(nums, idx + 2);
        int dont_rob_house = solve(nums, idx + 1);
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
        return solve(nums, 0);
    }
};

// Method2: bottom up
class SolutionTopDown {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n + 1, -1);

        t[0] = 0;
        t[1] = nums[0];

        if (n == 0) {
            return t[0];
        }
        if (n == 1) {
            return t[1];
        }

        for (int i = 2; i <= n; i++) {
            t[i] = max(t[n - 2] + nums[i], t[n - 1]);
        }

        return t[n];
    }
};

// Method3: bottom up + optimized space
class SolutionTopDownOptimized {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prevPrev = 0;
        int prev = nums[0];

        if (n == 0) {
            return prevPrev;
        }
        if (n == 1) {
            return prev;
        }

        for (int i = 2; i <= n; i++) {
            int skip = prev;
            int steal = prevPrev + nums[i - 1];
            int temp = max(skip, steal);
            prevPrev = prev;
            prev = temp;
        }

        return prev;
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    SolutionTopDownOptimized sol;
    cout << sol.rob(nums) << endl;
    return 0;
}