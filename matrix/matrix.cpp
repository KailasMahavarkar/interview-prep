#include <bits/stdc++.h>
using namespace std;

// row wise traversal --> row col -> matrix[row][col]
// col wise traversal --> col row -> matrix[row][col]

void printMatrix(vector<vector<int>> mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << mat[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printMatrixColwise(vector<vector<int>> mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    for (int col = 0; col < cols; col++) {
        for (int row = 0; row < rows; row++) {
            cout << mat[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> printMatrixDiagnoalUp(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = 0;

    // 1. find max cols size
    for (auto &row : mat) {
        cols = max(cols, (int)row.size());
    }

    // 2. fill matrix by 0 if its missing value
    for (auto &row : mat) {
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

int main() {
    // vector<vector<int>> mat = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {10},
    //     {14, 15, 16, 17}};

    vector<vector<int>> mat = {{6},
                               {8},
                               {6, 1, 6, 16}};

    vector<int>
        diagonalUp = printMatrixDiagnoalUp(mat);

    for (int num : diagonalUp) {
        cout << num << " ";
    }
    cout << endl;
}
