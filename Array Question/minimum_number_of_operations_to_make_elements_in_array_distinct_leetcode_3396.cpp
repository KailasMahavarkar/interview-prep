#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

class Solution {
   public:
    // nums = [ 1, 2, 3, 4, 3, 2, 3, 5, 7]
    // 7 -> add to set
    // 5 -> add to set
    // 3 -> add to set
    // 2 -> add to set
    // 3 -> already seen so break at this point
    // [1, 2, 3, 4, 3] & [2, 3, 5, 7]
    //              i
	// now we simply takeaway first 3 prefix elements -> (n / 3) but since we need ceil value we do (n + 3) / 3
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> seen;
        int i = nums.size() - 1;

        while (i >= 0 && !seen.count(nums[i])) {
            seen.insert(nums[i]);
            i--;
        }

		
        return (i + 3) / 3;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 3, 2, 3, 5, 7};
    cout << sol.minimumOperations(nums) << endl;  // Output: 2
}