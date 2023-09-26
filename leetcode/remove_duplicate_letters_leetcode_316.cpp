#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        stack<char> st;
        vector<int> lastCharIndex(26, 0);
        vector<bool> hasTaken(26, false);

        for (int i = 0; i < s.size(); i++) {
            lastCharIndex[s[i] - 'a'] = i;
        }

        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if (hasTaken[idx]) {
                continue;
            }

            // condition to pop elements into stack
            // for example "cbac" -> with index for abc [2, 1, 0]
            // we are have already processed 'c' -> stack has [c]
            // we are processing "b"
            // check1: s[i] < st.top() -> b < c ? yes
            // check2: lastCharIndex[st.top() - 'a'] > i   --> yes
            // we will see whatever in stack top later as well (lastCharIndex gurantees that)
            while (!st.empty() && s[i] < st.top() && lastCharIndex[st.top() - 'a'] > i) {
                hasTaken[st.top() - 'a'] = false;
                st.pop();
            }

            // condition to push element into stack
            st.push(s[i]);
            hasTaken[idx] = true;
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // since higher lexicographically element will be at top
        // when we pop it store in result .. it also at it at end... so need to reverse it
        reverse(begin(result), end(result));

        return result;
    }
};

int main() {
    Solution sol;
    string s = sol.removeDuplicateLetters("cbacdcbc");
    cout << "the smallest in lexicographical order is --> " << s << endl;
}