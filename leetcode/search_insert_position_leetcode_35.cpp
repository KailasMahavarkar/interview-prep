#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (target > nums[mid]) {
                s = mid + 1;
            }

            if (target < nums[mid]) {
                e = mid - 1;
            }
        }
        return s;
    }
};

int main() {
    vector<int> nums = {1,3,5,6};
    int target = 7;

    Solution sol;
    cout << "ans --> " << sol.searchInsert(nums, target) << endl;
}