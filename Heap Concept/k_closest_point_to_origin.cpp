#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        vector<vector<int>> result;

        int n = points.size();

        for (auto& point : points) {
            double dist = sqrt(pow(abs(point[0] - 0), 2) + pow(abs(point[1] - 0), 2));
            pq.push(make_pair(dist, point));

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
    vector<int> nums = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    Solution sol;
    vector<int> ans = sol.kClosest(nums, k);
    printVector(ans);
}