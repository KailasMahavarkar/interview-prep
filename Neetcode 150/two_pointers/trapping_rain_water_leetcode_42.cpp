#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/trapping-rain-water/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (BruteForce)
// TC : O(n)
// SC : O(n)
class SolutionBrute {
   public:
    int trap(vector<int>& h) {
        int n = h.size();
        if (n < 3) return 0;

        vector<int> prefixMax(n, 0);
        vector<int> suffixMax(n, 0);

        prefixMax[0] = h[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], h[i]);
        }

        suffixMax[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], h[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += min(prefixMax[i], suffixMax[i]) - h[i];
        }

        return result;
    }
};

class Solution {
   public:
    int trap(vector<int>& h) {
        int n = h.size();
        if (n < 2) return 0;

        int l = 0;
        int r = n - 1;
        int lmax = 0;
        int rmax = 0;
        int res = 0;

        while (l <= r) {
            if (h[l] <= h[r]) {  // water must be trapped withing h[l](low) to h[r](higher)
                // what if we found a tower which is more worthy of lmax
                if (h[l] >= lmax) {
                    lmax = h[l];
                } else {
                    res += lmax - h[l];
                }
                l++;
            } else {  // water must be trapped withing h[r](low) to h[l](higher)
                // what if we found a tower which is more worthy of lmax
                if (h[r] >= rmax) {
                    rmax = h[r];
                } else {
                    res += rmax - h[r];
                }
                r--;
            }
        }

        return res;
    }
};

int main() {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    SolutionBrute sol;
    int ans = sol.trap(heights);
    cout << "ans -->" << ans << endl;
}
