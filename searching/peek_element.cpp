#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;

        while (s < e) {
            // mid can never be peek element
            // if there exist number greater than mid
            if (nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            } else {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }

        return s;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution sol;
    cout << sol.findPeakElement(nums) << endl;
    return 0;
}