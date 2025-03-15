#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int m, const vector<string>& matrix) {
    int odd_rows = 0, odd_columns = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') {
                count++;
            };
        }
        if (count % 2 == 1) {
            odd_rows++;
        };
    }

    for (int j = 0; j < m; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == '1') count++;
        }
        if (count % 2 == 1) {
            odd_columns++;
        }
    }

    cout << max(odd_rows, odd_columns) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            cin >> matrix[i];
        }

        solve(n, m, matrix);
    }

    return 0;
}
