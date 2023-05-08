#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int LIS(vector<int> &arr, int index, int previousValue) {
        // 1. base case
        if (index == arr.size()) {
            return 0;
        }

        // 2. code flow
        int pick = 0;
        int unpick = 0;

        // we are doing comparision since we want longest increasing
        if (arr[index] > previousValue) {
            // if we do pick it then we should update previousValue
            pick = 1 + LIS(arr, index + 1, arr[index]);
        } else {

            // if we dont pick it then we should keep previousValue as same
            unpick = LIS(arr, index + 1, previousValue);
        }
        return max(pick, unpick);
    }
    int longestIncreasingSubsequence(vector<int> arr) {
        return LIS(arr, 0, -1);
    }
};

int main() {
    vector<int> sample = {5, 4, 11, 1, 16, 8};
    Solution sol;
    int ans = sol.longestIncreasingSubsequence(sample);
    cout << "ans --> " << ans << endl;
}