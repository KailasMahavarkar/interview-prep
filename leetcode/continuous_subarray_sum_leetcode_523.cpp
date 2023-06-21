#include <bits/stdc++.h>
using namespace std;

// Help -> neetcode
// my inital thought was sliding window but question becomes 
// how do we know when to slide the left side of window or right side of window

class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainder;
        remainder[0] = -1;
        int prefix = 0;

        for (int i=0; i < nums.size(); i++){
            total += nums[i];
            int rem = total % k;
            if (remainder.find(rem) == remainder.end()){
                // element not found
                remainder[rem] = i;
            }else if (i - remainder[rem] > 1){
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {23,2,6,4,7};
    int k = 13;
    Solution sol;
    bool ans = sol.checkSubarraySum(nums, k);
    cout << boolalpha << ans << endl;
}