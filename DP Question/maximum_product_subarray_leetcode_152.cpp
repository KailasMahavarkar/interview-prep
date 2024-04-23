#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/maximum-product-subarray/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int currMaxProduct = nums[0];
        int currMinProduct = nums[0];
        int globalMaxProduct = nums[0];

        for (int i = 1; i < n; i++) {
            int temp = currMaxProduct;
            currMaxProduct = max({nums[i], temp * nums[i], currMinProduct * nums[i]});
            currMinProduct = min({nums[i], temp * nums[i], currMinProduct * nums[i]});
            globalMaxProduct = max(globalMaxProduct, currMaxProduct);
        }
        return globalMaxProduct;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution sol;
    int ans = sol.maxProduct(nums);
    cout << "ans --> " << ans << endl;
}

// Theory:
// currMaxProductSubarr: tracks maximum product of a subarray that ends at the current index.
// currMinProductSubarr: tracks minimum product of a subarray that ends at the current index.

// The variable currMinProductSubarr is necessary because 
// the maximum product subarray problem also involves negative numbers. 

// When dealing with negative numbers, multiplying a negative number 
// with a negative number can result in a positive number, 
// which can lead to a maximum product.

// Consider this scenario: If you only keep track of the maximum product 
// (currMaxProductSubarr) and encounter a negative number after a 
// series of positive numbers, your product might become smaller instead
// of larger when multiplied by the negative number.

// By keeping track of both the maximum and minimum products, 
// you ensure that when encountering negative numbers, 
// you also consider the possibility of obtaining a larger product by
//  multiplying the negative number with the minimum product so far 
// (which might be a negative number itself). 

