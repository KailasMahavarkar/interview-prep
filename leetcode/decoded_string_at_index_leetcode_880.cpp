#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string decodeAtIndex(string s, int k) {
        int size = 0;
        int currLen = 0;
        for (char &c : s) {
            if (isdigit(c)) {
                size = size * (c - '0');
            } else {
                size += 1;
            }
        }

        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            k = k % size;

            if (k == 0 && isalpha(s[i])) {
                return string(1, s[i]);
            }

            if (isalpha(s[i])) {
                size -= 1;
            } else {
                size = size / (s[i] - '0');
            }
        }

        return "";
    }
};

int main() {
    Solution sol;
    string s = "a23";
    int k = 10;
    string ans = sol.decodeAtIndex(s, k);
    cout << "ans --> " << endl;
}