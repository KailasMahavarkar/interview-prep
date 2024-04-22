#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/132-pattern/description/
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
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int num3 = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int curr = nums[i];

            if (curr < num3) {
                return true;
            }

            while (!st.empty() && curr > st.top()) {
                num3 = st.top();
                st.pop();
            }
            st.push(curr);
        }

        return false;
    }
};

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    Solution s;
    cout << boolalpha << s.find132pattern(nums) << endl;
    return 0;
}