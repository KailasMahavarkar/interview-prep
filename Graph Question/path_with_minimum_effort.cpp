#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
typedef pair<int, pair<int, int>> ppi;

// Note: since all weight are 1 ... queue can be used instead of min-heap

void printVector(vector<vector<int>> arr) {
    for (auto& row : arr) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

void printPQ(priority_queue<ppi, vector<ppi>, greater<ppi>> pq) {
    // print all elements in pq
    while (!pq.empty()) {
        cout << pq.top().first << "(" << pq.top().second.first << "-" << pq.top().second.second << ")"
             << " ";
        pq.pop();
    }
    cout << endl;
    cout << endl;
}

class Solution {
   public:
    vector<vector<int>> directions{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n; 
        };

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        vector<vector<int>> result(m, vector<int>(n, 100));  // result is also M x N matrix

        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            int diff = pq.top().first;
            pair<int, int> coordinates = pq.top().second;

            int x = coordinates.first;
            int y = coordinates.second;
            pq.pop();

            for (auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_)) {
                    int absolute_difference = abs(heights[x][y] - heights[x_][y_]);
                    int maxDiff = max(absolute_difference, diff);

                    // since we are taking lowest distance path and storing it in each result cell
                    if (result[x_][y_] > maxDiff) {
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, {x_, y_}});

                        printVector(result);
                        printPQ(pq);
                    }
                }
            }
        }

        return result[m - 1][n - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {3, 6},
        {4, 7}};
    sol.minimumEffortPath(grid);
}