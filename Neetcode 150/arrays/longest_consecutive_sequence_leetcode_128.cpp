#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/longest-consecutive-sequence/description/
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
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int best = 1;
        for (auto& it : st) {
            if (st.find(it - 1) == st.end()) {
                int counter = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    counter++;
                }
                best = max(counter, best);
            }
        }
        return best;
    }
};

int main() {
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    Solution sol;
    int longest = sol.longestConsecutive(arr);
    cout << "longest --> " << longest << endl;
}
