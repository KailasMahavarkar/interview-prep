#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal -> sliding window + hashmap)
// TC : O(n)
// SC : O(n)
class Solution {
   public:
    int maxSubarrayLength(vector<int>& arr, int k) {
        unordered_map<int, int> hmap;
        int i = 0;
        int j = 0;
        int n = arr.size();
        int maxLength = 0;

        // i 
        // 1  3  2  1  2  4  2  4   
        //                   j
        
        // hmap
        // 1 -> 2
        // 3 -> 1
        // 2 -> 3  <- at this point 2nd while loop will run
        // 4 -> 1
        
        // 2nd while loop will run until we reach another arr[j] 

        while (j < n) {
            hmap[arr[j]]++;

            while (hmap[arr[j]] > k) {
                hmap[arr[i]]--;
                i++;
            }

            maxLength = max(maxLength, j - i + 1);
            j++;
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 2, 1, 2, 4, 2, 4};
    int k = 2;
    int answer = sol.maxSubarrayLength(arr, k);
    cout << "answer --> " << answer << endl;
}
