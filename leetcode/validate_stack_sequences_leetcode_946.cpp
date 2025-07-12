#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int m = popped.size();
        int i = 0;
        int j = 0;

        while (i < m && j < m) {
            st.push(pushed[i]);

            while (!st.empty() && j < m && st.top() == popped[j]) {
                st.pop();
                j++;
            }

            i++;
        }

        return st.empty();
    }
};

int main() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};

    Solution sol;
    bool ans = sol.validateStackSequences(pushed, popped);
    cout << "ans --> " << ans << endl;
}