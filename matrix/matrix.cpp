#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printMatrixColwise(vector<vector<int>> mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << mat[j][i] << " ";
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