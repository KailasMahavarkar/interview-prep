#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
*/

// Approach-1 (Normal)
// TC : O(1)
// SC : O(n) <- depends on how many string we encode

class Solution {
   public:
    // Encodes a URL to a shortened URL.
    int counter = 0;
    unordered_map<string, string> hmap;

    string encode(string longUrl) {
        hmap[to_string(counter)] = longUrl;
        return "http://tinyurl.com/" + to_string(counter++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string lookup = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return hmap[lookup];
    }
};

int main() {
    Solution s;
    string url = "https://leetcode.com/problems/design-tinyurl";
    cout << s.decode(s.encode(url)) << endl;
    return 0;
}
