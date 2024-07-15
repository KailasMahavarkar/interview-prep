#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isValid(string str) {
        stack<char> st;

        for (char s : str) {
            if (s == '{' || s == '(' || s == '[') {
                st.push(s);
            } else {
                if (st.empty()) {
                    return false;
                }

                if (
                    s == '}' && st.top() == '{' ||
                    s == ')' && st.top() == '(' ||
                    s == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {
    string str = "}}}}";
    Solution sol;
    bool ans = sol.validateParenthesis(str);
    cout << "ans --> " << boolalpha << ans << endl;
}