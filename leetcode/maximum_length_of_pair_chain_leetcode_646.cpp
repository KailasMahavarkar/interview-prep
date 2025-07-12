#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if (pairs.empty()) {
            return 0;
        }

        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int longestChain = 1;
        int prevEnd = pairs[0][1];

        for (int i = 1; i < pairs.size(); ++i) {
            cout << "prevEnd: " << prevEnd << endl;
            if (pairs[i][0] > prevEnd) {
                longestChain++;
                prevEnd = pairs[i][1];
                cout << pairs[i][0] << pairs[i][1] << endl;
            }
        }

        return longestChain;
    }
};

int main() {
    vector<vector<int>> pairs = {{-10, -8}, {-4, 7}, {-5, 0}, {-6, -4}, {1, 7}, {6, 10}, {8, 9}, {9, 10}};
    Solution sol;
    int answer = sol.findLongestChain(pairs);
    cout << "answer: " << answer << endl;
}