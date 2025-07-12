#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/group-anagrams/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(n)
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for (const string& word : strs) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());

            if (mp.find(sorted_word) == mp.end()) {
                mp[sorted_word] = {word};
            } else {
                mp[sorted_word].push_back(word);
            }
        }

        for(auto &wordMapping: mp){
            result.push_back(wordMapping.second);
        }

        return result;
    }
};

int main() {
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(words);

    for (auto& x : ans) {
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
}
