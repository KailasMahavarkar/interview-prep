#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printVector(vector<T> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

class Solution
{
public:
    int n;
    void dfsHelper(vector<int> adj[], int curr, vector<bool> &visited, vector<int> &result)
    {
        if (visited[curr])
            return;

        visited[curr] = true;
        result.push_back(curr);
        for (int v : adj[curr])
        {
            if (!visited[v])
            {
                dfsHelper(adj, v, visited, result);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> result;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfsHelper(adj, i, visited, result);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> adj[] = {{1, 3}, {2, 0}, {1}, {0}};

    Solution sol;
    vector<int> ans = sol.dfsOfGraph(4, adj);

    printVector(ans);

    // for (auto x : adj)
    // {
    //     printVector(x);
    // }
}