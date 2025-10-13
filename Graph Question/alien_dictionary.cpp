#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, set<char>> predecessors;  // predecessors[c] = what can come before c
        unordered_set<char> allChars;

        // Initialize all characters
        for (string& word : words) {
            for (char c : word) {
                allChars.insert(c);
                if (predecessors.find(c) == predecessors.end()) {
                    predecessors[c] = set<char>();
                }
            }
        }

        // Build predecessor relationships by comparing adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];

            // Invalid case: word1 is prefix of word2 but comes after
            if (word1.length() > word2.length() &&
                word1.substr(0, word2.length()) == word2) {
                return "";
            }

            // Find first differing character
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                char c1 = word1[j];
                char c2 = word2[j];

                if (c1 != c2) {
                    // c1 comes before c2, so c1 is predecessor of c2
                    predecessors[c2].insert(c1);
                    break;  // Only first difference matters
                }
            }
        }

        // Apply topological sort
        return topologicalSort(predecessors, allChars);
    }

   private:
    string topologicalSort(unordered_map<char, set<char>>& predecessors, unordered_set<char>& allChars) {
        string result = "";
        queue<char> q;

        for (char c : allChars) {
            if (predecessors[c].empty()) {
                q.push(c);
            }
        }

        while (!q.empty()) {
            char current = q.front();
            q.pop();
            result += current;
            allChars.erase(current);

            // Remove current from all predecessor sets
            // Check if any character now has no predecessors
            for (char c : allChars) {
                if (predecessors[c].erase(current) > 0) {  // If current was removed
                    if (predecessors[c].empty()) {
                        q.push(c);  // Now ready to process
                    }
                }
            }
        }

        return allChars.empty() ? result : "";
    }
};
int main() {
    Solution sol;
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << sol.alienOrder(words) << endl;
    return 0;
}