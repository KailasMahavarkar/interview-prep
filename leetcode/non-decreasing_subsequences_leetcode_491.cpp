#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    void backtrack(vector<int>& nums, int idx,  vector<int>& curr, vector<vector<int>>& result){

        // blindly append curr as result when i go back from recursion
        // reason: when i enter into recursion i will apply check at that point

        if (curr.size() >= 2){
            result.push_back(curr);
        }

        unordered_set<int> st;
        
        for (int i=idx; i < n; i++){

            // recursion should run in two scenarios
            // 1. array is empty
            // 2. prev elem which we have in curr set is >= what we are iterating at nums
            if ((curr.empty() || nums[i] >= curr.back()) && (st.find(nums[i]) == st.end() )){

                curr.push_back(nums[i]); // tick
                backtrack(nums, i + 1, curr, result);
                curr.pop_back(); // untick

                st.insert(nums[i]);
            } 
        }

        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> result; 
        vector<int> curr;
        backtrack(nums, 0, curr, result);
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4, 5, 7, 7};
    vector<vector<int>> ans = sol.findSubsequences(nums);

}