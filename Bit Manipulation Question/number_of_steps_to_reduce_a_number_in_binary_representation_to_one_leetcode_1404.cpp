#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(n)
// SC : O(n)
// Breaks since lonlong has maxlimit of 64 ... similar code works in python
class SolutionBruteForce {
   public:
    int numSteps(string s) {
        bitset<501> bs;
        for (int i = 0; i < s.length(); i++) {
            bs[s.length() - i - 1] = s[i] == '0' ? 0 : 1;
        }

        int count = 0;
        long long currVal = bs.to_ullong();

        while (currVal != 1) {
            cout << bs << endl;
            unsigned long l = bs.to_ullong();
            bs = bs[0] == 0 ? l / 2 : l + 1;
            count++;
            currVal = bs.to_ullong();
        }

        return count;
    }
};

class Solution {
   public:
    int numSteps(string s) {
        int count = 0;
        int n = s.size();
        int carry = 0;

        // This is actually pseudo loop -> what we are doing is taking LSB always
        for (int i = n - 1; i > 0; i--) {
            auto last = s[i] - '0';
            cout << "last: " << last << " count: " << count;
            if (last + carry == 0) {
                cout << " --> l+c = 1";
                carry = 0;
                count++;
            } else if (last + carry == 2) {
                cout << " --> l+c = 2";
                carry = 1;
                count++;
            } else {
                cout << " --> l+c = 1 or X";
                carry = 1;
                count += 2;
            }
            cout << " carry: " << carry << endl;
        }

        return count;
    }
};

int main() {
    string s = "100010";
    Solution sol;
    int ans = sol.numSteps(s);
    cout << "ans --> " << ans << endl;
}

// Explaination for optimala solution:
// last: 0 count: 0 --> l+c = 1 carry: 0
// last: 1 count: 1 --> l+c = X carry: 1
// last: 0 count: 3 --> l+c = X carry: 1
// last: 0 count: 5 --> l+c = X carry: 1
// last: 0 count: 7 --> l+c = X carry: 1
// ans --> 9