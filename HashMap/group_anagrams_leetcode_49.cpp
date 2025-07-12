#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hmap;

        for (const string& word : strs) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());

            if (hmap.find(sorted_word) == hmap.end()) {
                vector<string> word_list = {};
                word_list.push_back(word);
                hmap[sorted_word] = word_list;
            } else {
                hmap[sorted_word].push_back(word);
            }
        }

        vector<vector<string>> result;
        for (const auto& entry : hmap) {
            result.push_back(entry.second);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = sol.groupAnagrams(strs);

    for (const auto& group : groupedAnagrams) {
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}