#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class SolutionBruteForce {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        for (int s = 0; s <= n - 1; s++) {
            for (int e = s; e <= n - 1; e++) {
                int sum = 0;
                for (int i = s; i <= e; i++) {
                    sum += nums[i];
                }
                if (sum == k) {
                    result++;
                }
            }
        }

        return result;
    }
};

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int runningSum = 0;
        int result = 0;

        unordered_map<int, int> hmap;
        hmap.insert({0, 1});

        for (int i = 0; i < n; i++) {
            runningSum += nums[i];
            int diff = runningSum - k;

            if (hmap.find(diff) != hmap.end()) {
                // we seen this before
                result += hmap[diff];
            }

            hmap[runningSum]++;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 2;
    int ans = sol.subarraySum(nums, k);
    cout << "ans --> " << ans << endl;
}