#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/find-common-characters/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(N * L) -> Number of words * length of word
// SC : O(1)
class Solution {
   public:
    vector<int> getFrequency(string word) {
        vector<int> freq(26, 0);
        for (auto &x : word) {
            freq[x - 'a']++;
        }
        return freq;
    }

    vector<int> getMinimumFrequency(vector<int> &freq1, vector<int> &freq2) {
        for (int i = 0; i < 26; i++) {
            freq1[i] = min(freq1[i], freq2[i]);
        }
        return freq1;
    }

    vector<string> commonChars(vector<string> &words) {
        vector<int> globalMap(26, INT_MAX);

        for (auto &word : words) {
            vector<int> freq = getFrequency(word);
            globalMap = getMinimumFrequency(globalMap, freq);
        }
        vector<string> answer;

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < globalMap[i]; j++) {
                string s(1, i + 'a');
                answer.push_back(s);
            }
        }

        return answer;
    }
};

int main() {
    vector<string> words = {"bella", "label", "roller"};
    Solution sol;
    vector<string> answer = sol.commonChars(words);

    for (auto &x : answer) {
        cout << x << " ";
    }
    cout << endl;
}

//           a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
// bella ->[ 1   1   0   0   1   0   0   0   0   0   0   2   0   0   0 ]

//           a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
// lolla ->[ 1   0   0   0   0   0   0   0   0   0   0   3   0   0   1 ]

// -----------------------------------------------------------------------
// Min(all)  1   0   0   0   0   0   0   0   0   0   0   2   0   0   0