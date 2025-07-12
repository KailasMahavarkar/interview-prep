using namespace std;
#pragma GCC optimize("O3,unroll-loops")
// using unordered_map --> method-1
// class Solution {
// public:
//     void dfs(unordered_map<int, vector<int>> &adj, int curr,  vector<bool> &visited){
//         if (visited[curr]) return;
//         visited[curr] = true;

//         for (int &x: adj[curr]){
//             if (!visited[x]){
//                 dfs(adj, x, visited);
//             }
//         }

//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         unordered_map<int, vector<int>> adj;
//         vector<bool> visited(n, false);

//         int count = 0;

//         for (int i=0; i < n; i++){
//             for (int j=0; j < n; j++){
//                 if (isConnected[i][j] == 1){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }

//         for (int i=0; i < n; i++){
//             if (!visited[i]){
//                 dfs(adj, i, visited);
//                 count++;
//             }
//         }
//         return count;
//     }    
// };


// without using unordered_map --> method 2
class Solution {
public:
    int n = 0;
    void dfs(vector<vector<int>>& isConnected, int curr,  vector<bool> &visited){
        if (visited[curr]) return;
        visited[curr] = true;

        for (int v=0; v < n; v++){
            if (!visited[v] && isConnected[curr][v] == 1){
                dfs(isConnected, v, visited);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);

        int count = 0;

        for (int i=0; i < n; i++){
            if (!visited[i]){
                dfs(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }    
};
