#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
class Solution {
   public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;

        int n = nums.size();
        int s = 0;
        int e = n - 1;

        // 1. sort the array
        sort(nums.begin(), nums.end());

        // 2. precompute the powers
        vector<int> power(n, 0);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] << 1) % MOD;
        }

        // 3. code story
        int result = 0;
        while (s <= e) {
            int curr = nums[s] + nums[e];
            if (curr <= target) {
                result = ((int)result%MOD  + (int)power[e - s] % MOD) % MOD; 
                s++;
            } else {
                e--;
            }
        }
        return result % MOD;
    }
};


int main() {
    Solution s;
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    cout << s.numSubseq(nums, target) << endl;
    return 0;
}