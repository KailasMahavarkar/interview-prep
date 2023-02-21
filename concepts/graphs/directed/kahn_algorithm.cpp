//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        vector<int> result;
        queue<int> que;


        for (int i=0; i < V; i++){
            for (int &child: adj[i]){
                indegree[child]++;
            }
        }

        for (int i=0; i< V; i++){
            if (indegree[i] == 0){
                que.push(i);
            }
        }

        while (!que.empty()){
            int parent = que.front();
            result.push_back(parent);
            que.pop();


            for (int &child: adj[parent]){
                indegree[child]--;

                if (indegree[child] == 0){
                    que.push(child);
                }
            }
        }
        
        return result;
	}
};


int main(){
    Solution sol;

    vector<int> adj[6] = {{3, 2}, {4}, {3, 1}, {1}, {}, {1,4}};
    vector<int> ans = sol.topoSort(6, adj);

    for (auto &x: ans){
        cout << x << " ";
    } cout << endl;
}
