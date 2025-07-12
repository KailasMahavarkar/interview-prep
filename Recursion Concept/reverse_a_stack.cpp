#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

class Solution {
   public:
    void insertAtBottom(stack<int> &st, int element) {
        if (st.empty()) {
            st.push(element);
            return;
        }

        int top = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(top);
    }

    void Reverse(stack<int> &st) {
        if (st.empty()) {
            return;
        }
        int top = st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st, top);
    }
};

stack<int> vectorToStack(vector<int> &arr) {
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--) {
        st.push(arr[i]);
    }
    return st;
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        int top = st.top();
        cout << top << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    stack<int> initalStack = vectorToStack(arr);
    sol.Reverse(initalStack);
    printStack(initalStack);
}