#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    // Function to find the starting indices of anagrams of string p in string s
    vector<int> findAnagrams(string s, string p) {
        // Array to keep track of the frequency of characters in p
        int m[26] = {0};
        // Vector to store the starting indices of the anagrams
        vector<int> result; 

        // Create character map of p
        for (char c : p) {
            m[c - 'a']++;
        }

        // Two pointers to define the window
        int i = 0;
        int j = 0;
        // Variable to keep track of the number of characters in the window that match the frequency in the map
        int total = p.size();

        // Loop through the string s
        while (j < s.size()) {
            // Decrement the frequency of the current character in the map
            // If the frequency is greater than 0, it means the current character is in p
            if (m[s.at(j++) - 'a']-- > 0) {
                total--;
            }

            // If the frequency of all characters in the window is 0, it means the window contains an anagram of p
            if (total == 0) {
                result.push_back(i);
            }

            // Shift the window to the right by one character
            // Increment the frequency of the character that leaves the window in the map
            // If the frequency is 0 or greater, it means the character is in p
            if (j - i == p.size() && m[s.at(i++) - 'a']++ >= 0) {
                total++;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> answer = sol.findAnagrams("cbaebabacd", "abc");

    for (int i : answer) {
        cout << i << " ";
    }
    cout << endl;
}