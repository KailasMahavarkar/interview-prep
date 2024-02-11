#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/sort-characters-by-frequency/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()

class Solution {
   public:
    string frequencySort(string s) {
        vector<int> hmap(26, 0);

        for (auto &x : s) {
            if (x >= 'a' && x <= 'z') {
                hmap[x - 'a']++;
            }
        }

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (hmap[i] > 0) {
                pq.push({hmap[i], (char)(i + 'a')});
            }
        }

        string answer = "";
        while (!pq.empty()) {
            pair<int, char> t = pq.top();
            pq.pop();

            int freq = t.first;
            char character = t.second;

            for (int i = 0; i < freq; i++) {
                answer += character;
            }
        }

        return answer;
    }
};

int main() {
    string s = "hello world";
    Solution sol;
    string k = sol.frequencySort(s);

    cout << "k: --> " << k << endl;
}