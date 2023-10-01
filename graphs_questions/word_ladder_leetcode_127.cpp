#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> que;
        que.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());

        while (!que.empty()) {
            string word = que.front().first;
            int steps = que.front().second;
            que.pop();

            if (word == endWord) {
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {
                char originalWord = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        que.push({word, steps + 1});
                    }
                }
                word[i] = originalWord;
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int ans = sol.ladderLength(beginWord, endWord, wordList);
    cout << "ans --> " << ans << endl;
}