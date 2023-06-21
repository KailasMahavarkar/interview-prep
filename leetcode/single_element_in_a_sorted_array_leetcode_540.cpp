#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        cout << nums[10] << endl;

        while (s < e) {
            int mid = s + (e - s) / 2;
            bool sizeEven = (e - mid) % 2;
            if (!sizeEven) {
                mid = mid - 1;
            }
            if ((nums[mid] == nums[mid + 1]) && (nums[e] == nums[e - 1])) {
                // number kabhi yaha lie nahi karega
                e = mid - 1;
            }
            if ((nums[s] == nums[s + 1]) && (nums[mid] == nums[mid - 1])) {
                // number kabhi yaha lie nahi karega
                s = mid + 1;
            }

            // cout << "s :" << s << endl;
            // cout << "e : " << e << endl;
        }

        return nums[s];
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 3, 3};
    Solution sol;
    int ans = sol.singleNonDuplicate(nums);
    cout << "ans : " << ans << endl;
}