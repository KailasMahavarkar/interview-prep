#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printVector(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> frequencyMap;
        vector<int> result;

        int n = nums.size();

        // create frequency map
        for (int x : nums) {
            frequencyMap[x]++;
        }

        for (auto const& element : frequencyMap) {
            int curr_value = element.first;
            int curr_freq = element.second;

            pq.push(make_pair(curr_freq, curr_value));

            while (pq.size() > k) {
                pq.pop();
            }
        }

        while (pq.size() > 0) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);
    printVector(ans);
}