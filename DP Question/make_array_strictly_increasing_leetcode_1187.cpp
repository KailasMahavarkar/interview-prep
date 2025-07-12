#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <map>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/longest-string-chain/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(m*n*log(n))
// SC : O(m*n)

// Approach-1 (Using simple Recursion + Memoization) - O(n*n*log(n))
class Solution {
   public:
    map<pair<int, int>, int> mp;

    int solve(vector<int>& arr1, vector<int>& arr2, int idx, int prev) {
        if (idx >= arr1.size())
            return 0;

        int result1 = 1e9 + 1;

        if (mp.find({idx, prev}) != mp.end())
            return mp[{idx, prev}];

        if (arr1[idx] > prev) {
            result1 = solve(arr1, arr2, idx + 1, arr1[idx]);
        }

        int result2 = 1e9 + 1;
        auto it = upper_bound(begin(arr2), end(arr2), prev);

        if (it != end(arr2)) {
            int i = it - begin(arr2);
            result2 = 1 + solve(arr1, arr2, idx + 1, arr2[i]);
        }

        return mp[{idx, prev}] = min(result1, result2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2), end(arr2));
        mp.clear();

        int result = solve(arr1, arr2, 0, INT_MIN);

        if (result == 1e9 + 1)
            return -1;

        return result;
    }
};

// Approach 1: DP + binary search
// arr1 = {1, 5, 3, 7}
// 	          p  c
// arr2 = {1, 3, 2, 4}

// at this case if you try to greedily update prev with next upper_bound it will not work... since you will think.. if element more than 5 does not exists in arr2 then... it means we return -1... which is not true actually
// watch: https://youtu.be/ct036xxMtT8?t=297

// agar usss '5' ko bhi replace kar dete 2 se... toh hume answer mil jata... so

// we have two options
// 1. try the possibility even if prev > curr
// 2. fix this index with upper bound value

int main() {
    vector<int> arr1 = {1, 5, 3, 7};
    vector<int> arr2 = {1, 3, 2, 4};
    Solution sol;
    int ans = sol.makeArrayIncreasing(arr1, arr2);
    cout << "ans --> " << ans << endl;
}