#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/combination-sum-ii/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(n)
class Solution {
public:
    vector<vector<int>> result;
    void combination(vector<int>& candidates, int target, vector<int> curr, int idx) {
        if(target < 0)
            return;
        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1])
                continue; //ignore duplicate elements
            curr.push_back(candidates[i]);
            combination(candidates, target-candidates[i], curr, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); //because we will ignore duplicate elements
        combination(candidates, target, curr, 0);
        return result;
    }
};


int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum2(candidates, target);
    for (auto& arr : ans) {
        for (auto& x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
}
