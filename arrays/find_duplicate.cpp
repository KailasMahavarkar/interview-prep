#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        // 1, 3, 4, 2, 2
        // s
        //       f
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        // detect cycle
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
}