#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

void printVVI(vvi arr)
{
    for (vi x : arr)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    int m, n;

    int dfs(vvi& grid, int x, int y) {
        if( x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0) {
            return 1;
        }
        if(grid[x][y] == 5) {
            return 0;
        }

        grid[x][y] = 5;

        return dfs(grid, x + 1, y) + dfs(grid, x - 1, y) + dfs(grid, x, y + 1) + dfs(grid, x, y - 1);
    }
    int islandPerimeter(vvi& grid) {
        m = int(grid.size());
        n = int(grid[0].size());
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    ans += dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};

int main(){
    vvi grid = {
        {0,1,0},
        {0,1,0},
        {1,1,1}
    };

    cout << boolalpha;
    Solution mySol;
    int answer = mySol.islandPerimeter(grid);
    
    printVVI(grid);

    cout << answer << endl;
}
