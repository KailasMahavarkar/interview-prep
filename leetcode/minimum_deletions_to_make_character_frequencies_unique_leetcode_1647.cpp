#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int minDeletions(string s) {
        vector<int> fmap(26, 0);
        for (char &c : s) {
            fmap[c - 'a']++;
        }

        sort(fmap.begin(), fmap.end(), greater<int>());

        int minDel = 0;
        for (int i = 0; i < 25; i++) {
            if (fmap[i + 1] > 0) {
                if (fmap[i + 1] >= fmap[i]) {
                    int prev = fmap[i + 1];
                    fmap[i + 1] = max(0, fmap[i] - 1);
                    minDel += (prev - fmap[i + 1]);
                }
            }
        }

        return minDel;
    }
};
int main() {
    Solution sol;
    string s = "aaaabbbbccccdddd";
    int ans = sol.minDeletions(s);
    cout << "answer: " << ans << endl;
}