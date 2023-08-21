#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        vector<int> result = {};

        int i = 0;
        int j = 0;

        while (i <= nums.size() - k) {
            while (j != k - 1) {
                pq.push(nums[j]);
                j++;
            }

            i++;

            // find element in pq and remove it
            int element = nums[i - 1];
            auto it = find(pq.begin(), pq.end(), element);
            if (it != pq.end()) {
                pq.erase(it);
            }

            // push element at j
            pq.push(nums[j]);

            // push top element in result
            result.push_back(pq.top());

            // pop top element from pq
            pq.pop();

            // increment j
            j++;

            cout << "i: " << nums[i] << "    : j " << nums[j] << endl;
            cout << "top  --> " << pq.top() << endl;
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    // 3 3 5 5 6 7
    int k = 3;

    Solution sol;
    sol.maxSlidingWindow(nums, k);
}