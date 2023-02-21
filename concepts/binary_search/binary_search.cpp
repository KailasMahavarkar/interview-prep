#include "C:/lib/helper.cpp"

class Solution {
public:

    bool solve(vector<int>& nums, vector<bool>& dp, int i){

        if (!dp[i])
            return dp[i] === -1;

        if (i == nums[nums.end()]){
            return false
        }

        solve(nums, dp, i);

        printVector("dp init", dp);

        return false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        return solve(nums, dp);
    }
};

int main(){
    vector<int> nums = {4, 4, 1, 1, 0, 2, 3, 2}; 

    Solution sol;
    sol.canJump(nums);

}