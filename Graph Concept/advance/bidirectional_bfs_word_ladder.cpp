#include <climits>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void printSet(unordered_set<string>& st) {
        for (auto x : st) {
            cout << x << endl;
        }
        cout << endl;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end()) {
            return 0;
        }

        unordered_set<string> frontSet{beginWord};
        unordered_set<string> backSet{endWord};

        int level = 1;

        while (!frontSet.empty() && !backSet.empty()) {
            level++;

            // bidirectional BFS (expand the smaller size frontier)
            if (frontSet.size() > backSet.size()) {
                cout << "choosing backset with size " << backSet.size() << endl;
                printSet(backSet);
                swap(frontSet, backSet);
            } else {
                cout << "choosing frontset with size " << frontSet.size() << endl;
                cout << "words in frontset are: " << endl;
                printSet(frontSet);
            }

            unordered_set<string> nextLevel;

            // Expand current frontier (frontSet)
            for (const string& word : frontSet) {
                for (int i = 0; i < word.length(); i++) {
                    string newWord = word;

                    for (char c = 'a'; c <= 'z'; c++) {
                        newWord[i] = c;

                        if (newWord == word) continue;

                        if (backSet.count(newWord)) {
                            return level;
                        }

                        if (st.count(newWord)) {
                            nextLevel.insert(newWord);
                            st.erase(newWord);
                        }
                    }
                }
            }

            frontSet = nextLevel;
        }

        return 0;
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution sol;
    int steps = sol.ladderLength(beginWord, endWord, wordList);
    cout << "steps --> " << steps << endl;
}