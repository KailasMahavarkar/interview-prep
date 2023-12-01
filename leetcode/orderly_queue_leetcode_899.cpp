#include <bits/stdc++.h>
using namespace std;

/*
    Problem Link  : https://leetcode.com/problems/orderly-queue/
    Company Tags  : amazon
    references    : codestorywithmik
*/

// Approach-1 (trick + bruteforce)
// TC : O(len(s)) -> O(n)
// SC : O(1)

class Solution {
   public:
    string orderlyQueue(string s, int k) {
        // k > 1 -> sort and return
        // fact is when k is 2 -> i.e if we are given freedom to choose any two chars
        // we can always sort the string

        // k = 1 -> bruteforce
        // rotate 1st charactet and return lexicographically smallest
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        string answer = s;
        for (int i = 1; i < s.size(); i++) {
            string temp = s.substr(i) + s.substr(0, i);
            answer = min(temp, answer);
        }

        return answer;
    }
};

int main() {
    string s = "aconite";
    int k = 1;
    Solution sol;
    string answer = sol.orderlyQueue(s, k);
    cout << "answer --> " << answer << endl;
}