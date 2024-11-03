#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/3sum/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(m * n)
// SC : O(nlogn + (n^2))
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }

                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }

                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);

    for (auto &x : ans) {
        for (auto &y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}
