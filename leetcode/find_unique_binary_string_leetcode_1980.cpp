#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link  : https://leetcode.com/problems/find-unique-binary-string
    Company Tags  : google, meta, amazon
    references    : 
    1. https://walkccc.me/LeetCode/problems/1980/?h=1980.+find+unique+binary+string
*/

// Approach-1 (binary to string - index on array)
// TC : O(n)
// SC : O(n)

using namespace std;

class SolutionNaive {
   public:
    string findDifferentBinaryString(vector<string>& nums) {
        // observation by examples:
        // binary numbers can have maximum range of {0, pow(2, k)} -> k is size of single arr element
        // {111, 011, 001} -> len of each is 3... so max possible number are {0, pow(2, 3)} -> {0, 8}

        // Intuition:
        // we create a boolean map of size pow(2, k)
        // we iterate though given array, convert each binary to number and set its visited as true
        // we go through array once and if anyone of index is not visited we return its string value
        // Note: we need to return answer in same length as single arr element, so we take last k size only

        int currMaxLen = nums[0].size();
        int maxPossibleValue = pow(2, currMaxLen);
        vector<bool> intVisited(maxPossibleValue + 1, false);

        for (int i = 0; i < nums.size(); i++) {
            int x = stoi(nums[i], nullptr, 2);
            intVisited[x] = true;
        }

        string ans = "";

        for (int i = 0; i < intVisited.size(); i++) {
            if (!intVisited[i]) {
                ans = bitset<16>(i).to_string();
                break;
            }
        }

        return ans.substr(ans.length() - currMaxLen);
    }
};

class Solution {
   public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;

        // Flip i-th bit for each nums[i] so that ans is unique.
        for (int i = 0; i < nums.size(); ++i)
            ans += nums[i][i] == '0' ? '1' : '0';

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> arr = {"01", "10"};
    string ans = sol.findDifferentBinaryString(arr);
    cout << "int ->" << ans << endl;
    return 0;
}
