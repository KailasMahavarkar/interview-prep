#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://leetcode.com/problems/number-of-wonderful-substrings/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(N)
// SC : O(N)
class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll, ll> mp;

        mp[0] = 1; // past me i had seen cum_xor = 0
        int cum_xor = 0;
        ll result = 0;

        for(char &ch: word){
            cum_xor ^= (1 << (ch - 'a'));
            result += mp[cum_xor];

            for(char x = 'a'; x <= 'j'; x++){
                ll check_xor = (cum_xor ^ (1 << (x - 'a')));
                result += mp[check_xor];
            }
            mp[cum_xor]++;
        }

        return result;
    }
};
int main() {
    string k = "c";
    Solution sol;
    long long ans = sol.wonderfulSubstrings(k);
    cout << "ans --> " << ans << endl;
}
