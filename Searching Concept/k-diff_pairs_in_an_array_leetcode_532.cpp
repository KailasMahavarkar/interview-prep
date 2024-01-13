#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // TC = O(nlogn) + (O(n)*(log n))
    // TC = 2*O(nlogn)
    // TC = O(nlogn)
    int findPairs(vector<int>& nums, int k) {
        // sorting -> O(nlogn)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        // outer loop -> O(n)
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = nums[i] + k;
            int s = i + 1, e = n - 1;

            // inner loop -> O(log n) -> binary search
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (nums[mid] == target) {
                    count++;
                    break;
                } else if (nums[mid] < target) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;

    Solution sol;
    cout << sol.findPairs(nums, k) << endl;
    return 0;
}