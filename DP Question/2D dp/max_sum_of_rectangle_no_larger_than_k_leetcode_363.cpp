#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal -> 2D kadane's)
// TC : O(rows * cols * kadane's)
// SC : O(rows)
// Note: TC for this is amotized (since for case maxSum <= k we also have n^2 operation)
class Solution {
   public:
    // https://assets.leetcode.com/users/images/537bd0e6-e55f-4a40-9a1f-5adbee9ab06f_1598675784.1868393.png
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = INT_MIN;

        for (int left = 0; left < cols; left++) {
            vector<int> sums(rows, 0);
            for (int right = left; right < cols; right++) {
                // Calculate the cumulative sum of elements from left to right
                for (int i = 0; i < rows; i++) {
                    sums[i] += matrix[i][right];
                }

                // Find the maximum subarray sum of the sums array
                int maxSum = INT_MIN;
                int currentSum = 0;
                for (int i = 0; i < rows; i++) {
                    if (currentSum < 0) {
                        currentSum = 0;
                    }
                    currentSum += sums[i];
                    maxSum = max(maxSum, currentSum);
                }

                if (maxSum <= k) {
                    result = max(result, maxSum);
                } else {
                    for (int i = 0; i < cols; ++i) {
                        int sum = 0;
                        for (int j = i; j < rows; ++j) {
                            sum += sums[j];
                            if (sum <= k) {
                                result = max(result, sum);
                            }
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> arr = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}};

    int k = 2;

    Solution sol;
    int ans = sol.maxSumSubmatrix(arr, k);
    cout << "ans --> " << ans << endl;
}