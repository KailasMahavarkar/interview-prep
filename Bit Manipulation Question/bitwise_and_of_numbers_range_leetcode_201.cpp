#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/bitwise-and-of-numbers-range/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        string bits = "00000000000000000000000000000000";

        for (int i = left; i < right; i++) {
            int andOP = 0;
            for (int i = 0; i < 31; i++) {
                
            }
        }
    }
};

int main() {
    Solution sol;
    int answer = sol.rangeBitwiseAnd(5, 7);
    cout << "answer --> " << answer << endl;
}
