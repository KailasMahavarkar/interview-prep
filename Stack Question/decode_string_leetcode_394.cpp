#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/decode-string/description/
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O()
// SC : O()
class Solution {
   public:
    string decodeString(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            st.push(s[i]);
        };

        string globalString = "";
        while (st.size() > 1) {
            char top = st.top();
            if (top == ']') {
                st.pop();

                string localString = "";
                while(st.top() != '['){
                    localString += st.top();
                    st.pop();
                }

                
            }
        }
    }
};

int main() {
    string str = "2[2[aa]]";
    Solution sol;
    string answer = sol.decodeString(str);
    cout << "string --> " << answer << endl;
}
