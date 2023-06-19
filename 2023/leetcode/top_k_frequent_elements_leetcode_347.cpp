#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> frequencyMap;

        int n = nums.size();

        // create frequency map
        for (int x : nums) {
            frequencyMap[x]++;
        }

        // add elements in maxHeap
        for (const auto& entry : frequencyMap) {
            int key = entry.first;
            int count = entry.second;

            // push element in maxheap on basis of max frequency of that element
            // [5, 5, 5, 5, 2, 2, 2, 3]
            // 5 -> 4 (5 has occured 4 times)
            // while storing in max heap we will store it as (4, 5) 
            pq.push(make_pair(count, key));
        }

        vector<int> result;

        while (k > 0) {
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {6, 6, 6, 5, 5, 5, 5, 2, 2};
    vector<int> answer = sol.topKFrequent(nums, 2);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    cout << endl;
}