#include <bits/stdc++.h>
using namespace std;

// Failed Approach: Greedy (wont work)
// class Solution {
//    public:
//     int minOperations(vector<int>& nums, int x) {
//         int i = 0;
//         int j = nums.size() - 1;
//         int operations = 0;

//         while (i <= j) {
//             int leftMost = nums[i];
//             int rightMost = nums[j];

//             cout << nums[i] << " " << nums[j] << endl;

//             if (leftMost > x && rightMost > x) {
//                 break;
//             }

//             if (leftMost >= rightMost && leftMost <= x) {
//                 x -= nums[i];
//                 i++;
//                 operations++;
//             } else {
//                 x -= nums[j];
//                 j--;
//                 operations++;
//             }
//         }

//         if (x > 0){
//             return -1;
//         }

//         return operations == 0 ? -1 : operations;
//     }
// };

int main() {
    Solution sol;
    vector<int> nums{1, 1};
    int x = 3;
    cout << "ans: " << sol.minOperations(nums, x);
}