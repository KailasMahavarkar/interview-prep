#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/bitwise-and-of-numbers-range/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal) -> using right shift
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;

        while (left != right) {
            left >>= 1;
            right >>= 1;
            count++;
        }

        return (left << count);
    }
};

// Approach-2 (Normal) -> using bit clear concept
// TC : O(n)
// SC : O(1)
class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right = right & (right - 1);  // n & (n - 1)
        }

        return right;
    }
};

int main() {
    Solution sol;
    int answer = sol.rangeBitwiseAnd(5, 7);
    cout << "answer --> " << answer << endl;
}
