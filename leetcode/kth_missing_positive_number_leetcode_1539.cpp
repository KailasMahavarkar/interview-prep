#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> nums;

        for (int i = 1; i < 1001; i++) {
            nums.push_back(i);
        }

        for (int i = 0; i < arr.size(); i++) {
            nums[arr[i]] = -1;
        }

        int ans = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != -1) {
                if (k > 0) {
                    ans = i;
                } else {
                    break;
                }
                k--;
            }
            cout << "ans: " << ans << endl;
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 2;
    int ans = Solution().findKthPositive(arr, k);
    cout << "ans: " << ans << endl;
}