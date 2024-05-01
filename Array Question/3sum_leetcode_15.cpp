#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/3sum/description/
    Company Tags   : Many
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (set + sorting + two pointer)
// TC : O(n^2)
// SC : O(n)

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;

        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            // 1st element pe h toh kar dena
            // baki sare elments me i > 0 hoga vo time to eleminate duplicate
            // nums[i] ko nums[i - 1] se isliye compare kar rhe h q ki
            // agar let say i=4 me koi value nai mili
            // then next i=4 me bhi nai milegi

            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                while (j < k) {
                    int case1 = i != j && i != k && j != k;
                    int case2 = nums[i] + nums[j] + nums[k] == 0;

                    if (case1 && case2) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        s.insert(temp);
                        j++;
                        k--;
                    } else if (nums[i] + nums[j] + nums[k] < 0) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }

        vector<vector<int>> result(s.begin(), s.end());
        return result;
    }
};
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    Solution s;
    vector<vector<int>> result = s.threeSum(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}