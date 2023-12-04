#include <bits/stdc++.h>
using namespace std;

void printDP(vector<vector<int>> dp) {
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
   public:
    vector<vector<int>> dp;
    void solve(vector<string> words) {
        int start = 0;

        while (start < words.size()) {
            int end = start;
            int lineLength = 0;

            while (end < words.size() && lineLength + words[end].length() + end - start <= 16) {
                lineLength += words[end].length();
                end++;
            }

            start = end;
        }
    }
};

int main() {
    vector<string> words = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
    Solution().solve(words);
    return 0;
}
