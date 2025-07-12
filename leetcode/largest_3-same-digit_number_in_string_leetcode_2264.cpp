#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link  : https://leetcode.com/problems/largest-3-same-digit-number-in-string/
    Company Tags  :
    references    :
*/

// Approach-1 (basic loop)
// TC : O(n)
// SC : O(1)

class Solution {
   public:
    string largestGoodInteger(string num) {
        int maxNumber = -1;

        for (int i = 1; i < num.size() - 1; i++) {
            int number = num[i] - '0';
            if (num[i - 1] == num[i] && num[i] == num[i + 1]) {
                maxNumber = max((number * 100) + (number * 10) + number, maxNumber);
            }
        }
        if (maxNumber == -1) return "";
        return maxNumber == 0 ? "000" : to_string(maxNumber);
    }
};

int main() {
    string num = "6777133339";
    Solution sol;
    cout << "answer --> " << sol.largestGoodInteger(num) << endl;
}
