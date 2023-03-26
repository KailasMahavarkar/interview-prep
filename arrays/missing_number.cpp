#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        // [3, 0, 1, 4] -> sum is 8 -> summ (we calculate)
        // [0, 1, 2, 3] -> sum is 6 -> expected -> formula

        // thus missing number must:
        // summ (we calculated) - expected

        int sumN = n * (n + 1) / 2;
        return sumN - total;
    }
};

int main() {
    vector<int> arr = {3, 0, 1, 4};

    Solution obj;
    int ans = obj.missingNumber(arr);

    cout << "missing number is: " << ans << endl;
    return 0;
}
