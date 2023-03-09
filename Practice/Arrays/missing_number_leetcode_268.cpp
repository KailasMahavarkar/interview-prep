#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        // calc sum of first n natural numbers
        // n will always be more by 1
        int sumN = n * (n + 1) / 2;
        return sumN - total;
    }
};

int main() {
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int ans = Solution().missingNumber(nums);
    cout << "ans: " << ans << endl;
}