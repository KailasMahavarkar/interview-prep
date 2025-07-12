#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link  : https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor
    Company Tags  :
    references    : codestorywithmik
*/

// Approach-1 (simple iteratiron)
// TC : O(n)
// SC : O(n)
class Solution {
   public:
    int MOD = 1e7 + 9;
    int numberOfWays(string corridor) {
        // Step 1: build index vector for all places where 'S' occured
        vector<int> index_vec;
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S') {
                index_vec.push_back(i);
            }
        }

        if (index_vec.size() % 2 || index_vec.size() == 0)
            return 0;

        // Step 2: iterate array with step of 2 and find answer
        // Note: since we are iterating forwards answer must accumulate over time
        int result = 1;
        int last_seen_end_index = index_vec[1];
        for (int i = 2; i < index_vec.size(); i += 2) {
            int length = index_vec[i] - last_seen_end_index;
            result = (result * length) % MOD;
            last_seen_end_index = index_vec[i + 1];
        }

        return result;
    }
};

int main() {
    string corridor = "SSPPSPS";
    Solution sol;
    int answer = sol.numberOfWays(corridor);
    cout << "answer --> " << answer << endl;
}