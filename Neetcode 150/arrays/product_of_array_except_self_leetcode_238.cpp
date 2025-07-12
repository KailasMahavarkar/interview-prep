#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/product-of-array-except-self/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(n)
class SolutionSpace {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixLeft(n, 0);
        vector<int> prefixRight(n, 0);

        //         1, 2, 3, 4
        // left:   1  1  2  6
        // right: 24 12  4  1
        // ans:   24 12  8  6

        prefixLeft[0] = 1;
        for (int i = 1; i < n; i++) {
            prefixLeft[i] = nums[i - 1] * prefixLeft[i - 1];
        }

        prefixRight[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            prefixRight[i] = prefixRight[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            prefixLeft[i] *= prefixRight[i];
        }

        return prefixLeft;
    }
};

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        //         1, 2, 3, 4
        // left:   1  1  2  6
        // right: 24 12  4  1
        // ans:   24 12  8  6

        result[0] = 1;
        for (int i = 1; i < n; i++) {
            result[i] = nums[i - 1] * result[i - 1];
        }

        int acc = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * acc;
            acc *= nums[i];
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    vector<int> ans = sol.productExceptSelf(nums);
    for (auto& x : ans) cout << x << " ";
    cout << endl;
}
