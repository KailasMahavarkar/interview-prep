#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/combination-sum/
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
    int n;
    vector<vector<int>> answer;
    void solve(vector<int>& curr, vector<int>& arr, int target, int idx) {
        // maximum recursion depth candiates size ke barabar ho sakta h
        // meaning ... agar tum recursion tree bana dete hona tab observe karna
        // pick ke case me toh vo unlimited number of times chalega... isko limit karna padega
        // and yahi se recursion rollback bhi karenge hum
        if (idx == n) {
            if (target == 0) {
                answer.push_back(curr);
            }
            return;
        }

        // pick wala case
        if (arr[idx] <= target) {
            curr.push_back(arr[idx]);
            solve(curr, arr, target - arr[idx], idx);
            curr.pop_back();
        }

        // unpick wala case
        solve(curr, arr, target, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> curr;
        solve(curr, candidates, target, 0);
        return answer;
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(candidates, target);
    for (auto& arr : ans) {
        for (auto& x : arr) {
            cout << x << " ";
        }
        cout << endl;
    }
}
