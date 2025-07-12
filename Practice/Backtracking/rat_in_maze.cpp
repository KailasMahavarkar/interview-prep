#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printVVS(vector<string> strArray) {
    // Displaying the 2D vector
    for (int i = 0; i < strArray.size(); i++) {
        cout << strArray[i] << " ";
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> m, int n, int x, int y, vector<vector<int>> visited) {
    return (x >= 0 && x < n && y >= 0 && y < n && m[x][y] == 1 && visited[x][y] == 0);
}

void solve(vector<vector<int>> m, int n, vector<string> &ans, string path, int x, int y, vector<vector<int>> visited) {
    // base case
    // if we reached end of destination
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<pair<char, pair<int, int>>> directions = {
        {'D', {1, 0}},   // Down
        {'L', {0, -1}},  // Left
        {'R', {0, 1}},   // Right
        {'U', {-1, 0}}   // Up
    };

    for (auto &pair : directions) {
        char key = pair.first;

        int newX = pair.second.first + x;
        int newY = pair.second.second + y;

        if (isSafe(m, n, newX, newY, visited)) {
            path.push_back(key);
            solve(m, n, ans, path, newX, newY, visited);
            path.pop_back();
        }
    }

    // backtrack
    visited[x][y] = 0;
}

// m -> maze
// n -> size of maze 2d size | if n is 4 = 4x4 matrix
vector<string> findPath(vector<vector<int>> maze) {
    int n = maze.size();

    // initialize with 0
    vector<vector<int>> visited(n, vector<int>(n));
    vector<string> ans;
    string path = "";

    if (maze[0][0] == 0) {
        return ans;
    }

    solve(maze, n, ans, path, 0, 0, visited);
    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    vector<string> ans = findPath(maze);
    printVVS(ans);
}


// why is direction mapped different? like {'D', {1, 0}} ?
// the choice of coordinates might appear a bit counter intuitive at first glance. Let's break it down:
// In the Cartesian coordinate system:
// The x-axis typically represents horizontal movement (left and right).
// The y-axis typically represents vertical movement (up and down).
// However, in the context of this code:

// The maze is represented as a 2D grid where each cell can be accessed using coordinates (x, y),
// where x represents the row index and y represents the column index.

// In the maze representation, movement in the positive x-direction (+1 along the x-axis)
// indeed represents moving downwards because the origin (0,0) is typically at the top-left corner of the maze.
// So, as you move along the positive x-direction, you're moving downwards in the maze grid.
