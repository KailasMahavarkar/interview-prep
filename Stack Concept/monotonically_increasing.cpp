#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// Monotonic Stacks ensure that elements inside the stack are arranged
// in an increasing or decreasing order based on their arrival time.
vector<int> monotonicIncreasing(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> result;
    // Traverse the array
    for (int i = 0; i < n; ++i) {
        // While stack is not empty AND top of stack is more
        // than the current element
        while (!st.empty() && st.top() > nums[i]) {
            // Pop the top element from the
            // stack
            st.pop();
        }
        // Push the current element into the stack
        st.push(nums[i]);
    }

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    vector<int> result = monotonicIncreasing(nums);
    cout << "Monotonic increasing stack: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}