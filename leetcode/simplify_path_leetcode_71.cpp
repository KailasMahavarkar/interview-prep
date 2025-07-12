#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token = "";
        stack<char> st;

        while (getline(ss, token, "/")) {
            if (token == "" || token == ".") continue;

            if (token != "..")
                st.push(token);
            else if (!st.empty())
                st.pop();
        }

        if (st.empty()) {
            return "/";
        }

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.top();
        }

        return result;
    }
};

int main() {
    string str = "/home/";
    Solution sol;
    string ans = sol.simplifyPath(str);
    cout << "ans --> " << ans << endl;
}