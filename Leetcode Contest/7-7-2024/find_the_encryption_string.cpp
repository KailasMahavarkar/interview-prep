#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string getEncryptedString(string s, int k) {
        string cpy = s;
        unordered_map<char, int> hmap;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            // pi -> possible index
            s[i] = cpy[(n + i + k) % n];
        }

        return s;
    }
};

int main() {
    Solution sol;
    string s = "dart";
    int k = 3;
    string answer = sol.getEncryptedString(s, k);

    cout << "ans --> " << answer << endl;
}