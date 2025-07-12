#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
class Solution {
   public:
    string removeStars(string s) {
        string result = "";

        for (char &ch : s) {
            if (ch == '*') {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }

        return result;
    }
};

int main() {
    string str = "leet**cod*e";
    Solution sol;
    string ans = sol.removeStars(str);
    cout << "ans --> " << ans << endl;
}