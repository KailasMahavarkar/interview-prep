#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printVector(vector<int>& nums) {
    for (auto x : nums) {
        cout << x << " ";
    }
    cout << endl;
}

void printPQ(priority_queue<int>& pq) {
    // print pq elements and then restore it
    priority_queue<int> temp = pq;
    while (temp.empty() == false) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // restore pq
    while (pq.empty() == false) {
        temp.push(pq.top());
        pq.pop();
    }

    while (temp.empty() == false) {
        pq.push(temp.top());
        temp.pop();
    }
}

// print min heap
void printPQMIN(priority_queue<int, vector<int>, greater<int>>& pq_min) {
    // print pq elements and then restore it
    priority_queue<int, vector<int>, greater<int>> temp = pq_min;
    while (temp.empty() == false) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // restore pq
    while (pq_min.empty() == false) {
        temp.push(pq_min.top());
        pq_min.pop();
    }

    while (temp.empty() == false) {
        pq_min.push(temp.top());
        temp.pop();
    }
}

class Solution {
   public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int> pq;

        int GMIN = nums[0] * 2;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) {
                nums[i] = nums[i] * 2;
            }
            pq.push(nums[i]);
            GMIN = min(nums[i], GMIN);
        }

        int dev = pq.top() - GMIN;

        while (pq.top() % 2 == 0) {
            int top = pq.top();
            pq.pop();

            pq.push(top / 2);

            dev = min(dev, top - GMIN);
            GMIN = min(GMIN, top / 2);
        }

        return min(dev, pq.top() - GMIN);
    }
};

void testCaseRunner(vector<pair<vector<int>, int>> testcases) {
    Solution sol;
    int count = 0;
    int passedCount = 0;
    int failedCount = 0;

    for (auto testcase : testcases) {
        count++;

        int dev = sol.minimumDeviation(testcase.first);
        cout << endl;
        cout << "case" << count << " : ";
        for (auto x : testcase.first) {
            cout << x << " ";
        }
        cout << endl;

        cout << "--> current is " << dev << endl;
        cout << "--> expected is " << testcase.second << endl;

        if (dev == testcase.second) {
            cout << "----> passed" << endl;
            passedCount++;
        } else {
            cout << "X---X failed" << endl;
        }
        cout << endl;
    }

    cout << "passed " << passedCount << " of " << count << " testcases" << endl;
}
int main() {
    vector<pair<vector<int>, int>> testcases = {
        {{10, 4, 3}, 2},
        {{3, 5}, 1},
        {{1, 16}, 0},
        {{1, 2, 3, 4}, 1},
        {{4, 1, 5, 20, 3}, 3}};

    testCaseRunner(testcases);
}