#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

void printVVI(vvi arr){
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[0].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
    public:
        int memo[51][51][51];
        int mod = 1000000007; // 10^9 + 7

        long solve(int m, int n, int maxMove, int i, int j){

            // out of boundary -> return 1
            if (i >= m || i < 0 || j >= n || j < 0){
                return 1;
            }

            // if moves exceeded 
            if (maxMove <= 0){
                return 0;
            }

            // memoize value for dfs
            if (memo[i][j][maxMove] != -1){
                return memo[i][j][maxMove];
            }

            // dfs call
            long res = 0;
            res += solve(m, n, maxMove-1, i+1, j);
            res += solve(m, n, maxMove-1, i-1, j);
            res += solve(m, n, maxMove-1, i, j+1);
            res += solve(m, n, maxMove-1, i, j-1);

            return memo[i][j][maxMove] = res % mod;
        }
        
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

            // create a memset
            memset(memo, -1, sizeof(memo));
            return solve(m, n, maxMove, startRow, startColumn);
        }
};

int main(){
    //  m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
    Solution sol;
    sol.findPaths(1, 3, 3, 0, 1);
}