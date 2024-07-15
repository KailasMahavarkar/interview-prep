#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

/*
    Problem Link   : https://leetcode.com/problems/min-stack/description/
    Company Tags   : bloomberg
    Youtube Link   : https://www.youtube.com/watch?v=LaBE0gNYCaM&ab_channel=codestorywithMIK
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(1)
// SC : O(n)
class MinStack {
   public:
    stack<int> st;
    stack<int> minStack;

    MinStack() {
        minStack.push(INT_MAX);
    }

    void push(int val) {
        if (val <= minStack.top()) {
            minStack.push(val);
        }

        st.push(val);
    }

    void pop() {
        if (st.top() == minStack.top()) {
            minStack.pop();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack* obj = new MinStack();

    obj->push(-2);
    cout << "Pushed: -2" << endl;

    obj->push(0);
    cout << "Pushed: 0" << endl;

    obj->push(-3);
    cout << "Pushed: -3" << endl;
    cout << "Minimum: " << obj->getMin() << endl;  // Returns -3

    obj->pop();
    cout << "Popped" << endl;
    cout << "Top: " << obj->top() << endl;         // Returns 0
    cout << "Minimum: " << obj->getMin() << endl;  // Returns -2

    delete obj;
    return 0;
}
