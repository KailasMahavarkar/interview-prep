#include <bits/stdc++.h>
using namespace std;

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

void printVVI(vector<vector<int>> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> nums = {12, 3, 4, 1, 6, 9};
    int target = 25;

    vector<vector<int>> result = findTriplets(nums, nums.size(), target);
    printVVI(result);

    return 0;
}