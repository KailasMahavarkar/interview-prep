#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
   public:
    int m, n;
    bool isSafe(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        queue<pair<int, int>> que;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        que.push({sr, sc});

        int oldColor = image[sr][sc];
        int newColor = color;

        if (oldColor == newColor) {
            return image;
        }

        while (!que.empty()) {
            int i = que.front().first;
            int j = que.front().second;
            que.pop();

            for (auto& dir : directions) {
                int _i = dir[0] + i;
                int _j = dir[1] + j;

                if (isSafe(_i, _j) && image[_i][_j] == oldColor) {
                    que.push({_i, _j});
                    image[_i][_j] = newColor;
                }
            }
        }

        // fill source with new color
        if (image[sr][sc] != color) {
            image[sr][sc] = color;
        }

        return image;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    Solution sol;
    vector<vector<int>> ans = sol.floodFill(grid, 1, 1, 2);

    for (auto& row : ans) {
        for (int& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}