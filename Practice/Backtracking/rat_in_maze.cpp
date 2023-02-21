#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<int> vi;

void printVVI(vvi matrix){
    // Displaying the 2D vector
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void printVVS(vs strArray){
    // Displaying the 2D vector
    for (int i = 0; i < strArray.size(); i++) {
            cout << strArray[i] << " ";
    } cout << endl;
}

bool isSafe(vvi m,int n, int x, int y, vvi visited){

    // if (x,y) has NOT outsize matrix
    if ((x >= 0 && x < n) && (y >= 0 && y < n)){
        // 1 means path is open
        // 0 means path is closed
        if (m[x][y] == 1){
            // 1 means already visited
            // 0 means not visited
            if (visited[x][y] == 0){
                return true;
            }
        }
    }
    return false;
}

void solve(vvi m,int n, vs &ans, string path, int x, int y,vvi visited){
    // base case
    // if we reached end of destination
    if (x == n-1 && y == n - 1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // movement for down
    int newX = x+1;
    int newY = y;
    if (isSafe(m, n, newX, newY, visited)){
        path.push_back('D');
        solve(m, n, ans, path, newX, newY, visited);
        path.pop_back();
    }

    // movement for left
    newX = x;
    newY = y - 1;
    if (isSafe(m, n, newX, newY, visited)){
        path.push_back('L');
        solve(m, n, ans, path, newX, newY, visited);
        path.pop_back();
    }

    // movement for right
    newX = x;
    newY = y + 1;
    if (isSafe(m, n, newX, newY, visited)){
        path.push_back('R');
        solve(m, n, ans, path, newX, newY, visited);
        path.pop_back();
    }
    
    // movement for up
    newX = x - 1;
    newY = y;
    if (isSafe(m, n, newX, newY, visited)){
        path.push_back('U');
        solve(m, n, ans, path, newX, newY, visited);
        path.pop_back();
    }

    // backtrack
    visited[x][y] = 0;
}


// m -> maze
// n -> size of maze 2d size | if n is 4 = 4x4 matrix
vs findPath(vvi maze){
    int n = maze.size();

    // initialize with 0
    vvi visited(n, vi(n));
    int srcX = 0;
    int srcY = 0;
    vs ans;
    string path = "";

    if (maze[0][0] == 0){
        return ans;
    }

    solve(maze, n, ans, path, srcX, srcY, visited);
    sort(ans.begin(), ans.end());

    return ans;

}

int main(){
    vvi maze = {
        {1,0,0,0},
        {1,1,0,1}, 
        {1,1,0,0}, 
        {0,1,1,1}
    };
    vs ans = findPath(maze);
    printVVS(ans);

}