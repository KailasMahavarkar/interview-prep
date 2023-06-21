#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        int idx = 0;
        for (int i = 0; i < hLen; i++) {
            if (haystack[i] == needle[idx]) {
                idx++;
            } else {
                // slide the left window to [idx] amount to restart the search
                i = i - idx;
                // reset idx to 0
                // this is to reset needle starting point
                idx = 0;
            }
            if (idx == nLen) {
                return i - nLen + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int ans = sol.strStr("sadbutsade", "sade");
    cout << "ans: " << ans << endl;
}