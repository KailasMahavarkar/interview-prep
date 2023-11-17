#include <bits/stdc++.h>
using namespace std;

class Solution {
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

int main() {
    Solution sol;
    vector<string> arr = {"01","10"};
    string ans = sol.findDifferentBinaryString(arr);
    cout << "int ->" << ans << endl;
    return 0;
}
