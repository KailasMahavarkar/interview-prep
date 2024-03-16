#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> initalVector = {1, 0, 1, 0, 0};
    vector<int> zeroPrefixes = {0, 0, 0, 0};
    vector<int> onePrefixes = {0, 0, 0, 0};

    int zeroSum = 0;
    int oneSum = 0;
    int prefixSum(vector<int>& arr) {
        int maxLen = 0;

        for (int i = 0; i < zeroPrefixes.size(); i++) {
            zeroPrefixes[i] = initalVector[i] == 0 ? (zeroSum += 1) : (zeroSum);
            onePrefixes[i] = initalVector[i] == 1 ? (oneSum += 1) : (oneSum);
        }

        for (int i = 0; i < zeroPrefixes.size(); i++) {
            if (zeroPrefixes[i] == onePrefixes[i]) {
                maxLen = max(maxLen, zeroPrefixes[i]);
            }
        }
        return maxLen;
    }
};

int main() {
    vector<int> arr = {4, 3, 5, 2};
    Solution sol;
    int ans = sol.prefixSum(arr);
    cout << "ans --> " << ans << endl;
}