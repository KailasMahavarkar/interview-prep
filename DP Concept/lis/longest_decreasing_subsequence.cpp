#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int LDS(vector<int> &arr, int index, int previousValue) {
        // 1. base case
        if (index == arr.size()) {
            return 0;
        }

        // 2. code flow
        int pick = 0;
        int unpick = 0;

        // we are doing comparision since we want longest decreasing
        if (arr[index] < previousValue) {
            // if we do pick it then we should update previousValue
            pick = 1 + LDS(arr, index + 1, arr[index]);
        } else {
            // if we dont pick it then we should keep previousValue as same
            unpick = LDS(arr, index + 1, previousValue);
        }
        return max(pick, unpick);
    }
    int longestDecreasingSubsequence(vector<int> arr) {
        return LDS(arr, 0, INT_MAX);
    }
};

int main() {
    vector<int> sample = {5, 4, 3, 2, 1};
    Solution sol;
    int ans = sol.longestDecreasingSubsequence(sample);
    cout << "ans --> " << ans << endl;
}