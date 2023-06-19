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

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}};

    printMatrixColwise(mat);
}