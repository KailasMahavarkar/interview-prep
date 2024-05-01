#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/sort-colors/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O(N)
// SC : O(N)

void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0)
            count0++;
        else if (nums[i] == 1)
            count1++;
        else
            count2++;
    }

    int i = 0;
    while (count0 > 0) {
        nums[i++] = 0;
        count0--;
    }

    while (count1 > 0) {
        nums[i++] = 1;
        count1--;
    }

    while (count2 > 0) {
        nums[i++] = 2;
        count2--;
    }
}

int main() {
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sortColors(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}
