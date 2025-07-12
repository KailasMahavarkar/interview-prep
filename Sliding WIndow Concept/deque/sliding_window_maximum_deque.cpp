#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    void printWindow(deque<int> &dq) {
        for (auto &x : dq) {
            cout << x << " ";
        }
        cout << endl;
    }

    int getWindowMax(deque<int> &dq) {
        int maxx = INT_MIN;
        for (auto &x : dq) {
            maxx = max(maxx, x);
        }
        return maxx;
    }

    vector<int> maxSlidingWindowBruteforce(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> result;
        deque<int> window;

        for (int i = 0; i < n; i++) {
            // step -> make space for nums[i]
            // window size should not be greater than k
            int current = arr[i];

            if (window.size() >= k) {
                window.pop_front();
            }
            window.push_back(current);

            if (window.size() == k) {
                result.push_back(getWindowMax(window));
            }
        }

        return result;
    }

    vector<int> maxSlidingWindow(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> result;
        deque<int> window;
        deque<int> windowIndexed;

        for (int i = 0; i < n; i++) {
            // step -> make space for nums[i]
            // window size should not be greater than k
            int current = arr[i];
            // arr =       1   3  -1  -3   5   3   6   7
            //             0   1   2   3   4   5   6   7
            // k = 3
            // -------------------------------------------------------------------
            // i = 0
            // arr[i] = 1
            // No expired elements to remove
            // No elements in deque to compare, so push index 0
            // windowIndexed = [0]
            // window        = [1]
            // result        = [] (since i < k-1)
            // -------------------------------------------------------------------
            // i = 1
            // arr[i] = 3
            // Check outdated: windowIndexed.front() = 0 → 0 <= 1 - 3 → false
            // Check back: arr[1] >= arr[0] → 3 >= 1 → pop 0
            // After popping: windowIndexed = [], window = []
            // Push index 1
            // windowIndexed = [1]
            // window        = [3]
            // result        = [] (since i < k-1)
            // -------------------------------------------------------------------
            // i = 2
            // arr[i] = -1
            // Check outdated: windowIndexed.front() = 1 → 1 <= 2 - 3 → false
            // Check back: arr[2] >= arr[1] → -1 >= 3 → false
            // Push index 2
            // windowIndexed = [1, 2]
            // window        = [3, -1]
            // result        = [3] (max = arr[1] = 3)
            // -------------------------------------------------------------------
            // i = 3
            // arr[i] = -3
            // Check outdated: windowIndexed.front() = 1 → 1 <= 3 - 3 → false
            // Check back: arr[3] >= arr[2] → -3 >= -1 → false
            // Push index 3
            // windowIndexed = [1, 2, 3]
            // window        = [3, -1, -3]
            // result        = [3, 3] (max = arr[1] = 3)
            // -------------------------------------------------------------------
            // i = 4
            // arr[i] = 5
            // Check outdated: windowIndexed.front() = 1 → 1 <= 4 - 3 → true → pop front
            // After popping: windowIndexed = [2, 3], window = [-1, -3]
            // Check back: arr[4] >= arr[3] → 5 >= -3 → pop 3
            //              arr[4] >= arr[2] → 5 >= -1 → pop 2
            // After popping: windowIndexed = [], window = []
            // Push index 4
            // windowIndexed = [4]
            // window        = [5]
            // result        = [3, 3, 5] (max = arr[4] = 5)
            // -------------------------------------------------------------------
            // i = 5
            // arr[i] = 3
            // Check outdated: windowIndexed.front() = 4 → 4 <= 5 - 3 → false
            // Check back: arr[5] >= arr[4] → 3 >= 5 → false
            // Push index 5
            // windowIndexed = [4, 5]
            // window        = [5, 3]
            // result        = [3, 3, 5, 5] (max = arr[4] = 5)
            // -------------------------------------------------------------------
            // i = 6
            // arr[i] = 6
            // Check outdated: windowIndexed.front() = 4 → 4 <= 6 - 3 → false
            // Check back: arr[6] >= arr[5] → 6 >= 3 → pop 5
            //              arr[6] >= arr[4] → 6 >= 5 → pop 4
            // After popping: windowIndexed = [], window = []
            // Push index 6
            // windowIndexed = [6]
            // window        = [6]
            // result        = [3, 3, 5, 5, 6] (max = arr[6] = 6)
            // -------------------------------------------------------------------
            // i = 7
            // arr[i] = 7
            // Check outdated: windowIndexed.front() = 6 → 6 <= 7 - 3 → false
            // Check back: arr[7] >= arr[6] → 7 >= 6 → pop 6
            // After popping: windowIndexed = [], window = []
            // Push index 7
            // windowIndexed = [7]
            // window        = [7]
            // result        = [3, 3, 5, 5, 6, 7] (max = arr[7] = 7)
            // -------------------------------------------------------------------

            // remove outdated element from window (not part of current widow)
            while (!windowIndexed.empty() && windowIndexed.front() <= i - k) {
                windowIndexed.pop_front();
                window.pop_front();
            }


            // maintain monotonic decreasing property
            while (!windowIndexed.empty() && arr[i] >= arr[windowIndexed.back()]) {
                windowIndexed.pop_back();
                window.pop_back();
            }

            windowIndexed.push_back(i);
            window.push_back(arr[i]);

            printWindow(window);
            printWindow(windowIndexed);
            cout << endl;

            if (i >= k - 1) {
                result.push_back(arr[windowIndexed.front()]);
            }
        }

        return result;
    }
};

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution sol;
    vector<int> result = sol.maxSlidingWindow(arr, 3);
    for (auto &x : result) {
        cout << x << " ";
    }
    cout << endl;
}
