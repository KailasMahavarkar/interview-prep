#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link  : https://leetcode.com/problems/diagonal-traverse-ii/description/
    Company Tags  : google
    references    : codestorywithmik
*/

// Approach-1 (trick)
// TC : O(m * n)
// SC : O(1)

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> que;
        que.push({0, 0});
        vector<int> result;

        while (!que.empty()) {
            pair<int, int> temp = que.front();
            int row = temp.first;
            int col = temp.second;

            que.pop();
            result.push_back(nums[row][col]);

            if (col == 0 && row + 1 < nums.size()) {
                que.push({row + 1, col});
            }

            // agar niche right ke side column availbale h toh push karo
            if (col + 1 < nums[row].size()) {
                que.push({row, col + 1});
            }
        }

        return result;
    }
};

// Approach-2 (bruteforce using BFS -> failed MLE)
// TC : O(m * n)
// SC : O(m * n)
class SolutionCustom {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = 0;

        // 1. find max cols size
        for (auto& row : mat) {
            cols = max(cols, (int)row.size());
        }

        // 2. fill matrix by 0 if its missing value
        for (auto& row : mat) {
            while (row.size() < cols) {
                row.push_back(-1);
            }
        }

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        auto isSafe = [&](int x, int y) {
            return x < rows && x >= 0 && y >= 0 && y < cols && !visited[x][y];
        };

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<int> answer;
        queue<pair<int, int>> que;
        answer.push_back(mat[0][0]);
        que.push({0, 0});
        visited[0][0] = true;

        while (!que.empty()) {
            int levelSize = que.size();

            for (int i = 0; i < levelSize; i++) {
                pair<int, int> temp = que.front();
                que.pop();

                for (auto dir : directions) {
                    int _x = temp.first + dir[0];
                    int _y = temp.second + dir[1];

                    if (isSafe(_x, _y) && mat[_x][_y] != -1) {
                        answer.push_back(mat[_x][_y]);
                        que.push({_x, _y});
                        visited[_x][_y] = true;
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {10},
        {14, 15, 16, 17}};

    Solution sol;

    vector<int>
        diagonalUp = sol.findDiagonalOrder(mat);

    for (int num : diagonalUp) {
        cout << num << " ";
    }
    cout << endl;
}
