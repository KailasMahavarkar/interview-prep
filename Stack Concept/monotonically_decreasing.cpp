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
vector<int> monotonicDecreasing(vector<int> &nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> result;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() < nums[i]) {
            st.pop();
        }
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
    vector<int> result = monotonicDecreasing(nums);
    cout << "Monotonic increasing stack: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}