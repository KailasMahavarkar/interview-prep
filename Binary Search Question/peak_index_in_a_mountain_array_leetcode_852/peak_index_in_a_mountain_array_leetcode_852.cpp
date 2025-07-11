#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Binary Search)
// TC : O(logn)
// SC : O(1)
class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // arr[mid] can never be my peak since we have element more than arr[mid]
            if (arr[mid] < arr[mid + 1]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return s;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 3, 2, 1, 0};
    Solution sol;
    int answer = sol.peakIndexInMountainArray(arr);
    cout << "answer --> " << answer << endl;
}
