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

class Solution
{
public:
    int L, M;
    int maxArea = 0;

    int dfs(vvi &grid, int i, int j, int &area){
        int cMax = 1;
        if( i >= 0 && i < L && j >= 0 && j < M && grid[i][j] == 1){
            grid[i][j] = 0;
            
            cMax += dfs(grid, i-1, j, area);
            cMax += dfs(grid, i+1, j, area);
            cMax += dfs(grid, i, j-1, area);
            cMax += dfs(grid, i, j+1, area);

            return cMax;
        }
        return 0;
    }


    int maxAreaOfIsland(vvi &grid){
        L = grid.size();
        M = grid[0].size();

       for(int i = 0; i < L; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    int cMax = dfs(grid, i, j, area);
                    maxArea = max(maxArea, cMax);
                }
            }
        }
        return maxArea;
    }
};

int main()
{

    vvi grid = { 
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };

   

    Solution mySol;
    int ans = mySol.maxAreaOfIsland(grid);
    cout << "ans -->" << ans << endl;
    // printVVI(grid);
}