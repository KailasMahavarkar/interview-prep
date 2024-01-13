#include <bits/stdc++.h>
using namespace std;

// Approach 1: Kahn's Algorithm
class Solution {
   public:
    vector<int> kahnsAlgorithm(unordered_map<int, vector<int>> &adj) {
        vector<int> result;
        unordered_map<int, int> indegree;

        // calculate indegree
        for (auto &p : adj) {
            int node = p.first;
            indegree[node] = 0;
        }

        for (auto &p : adj) {
            int node = p.first;
            for (int &child : p.second) {
                indegree[child]++;
            }
        }

        // push all nodes with indegree 0 into queue
        queue<int> que;
        for (auto &p : indegree) {
            if (p.second == 0) {
                que.push(p.first);
            }
        }

        // pop from queue and push into result
        while (!que.empty()) {
            int node = que.front();
            que.pop();
            result.push_back(node);

            // reduce indegree of all children
            for (int &child : adj[node]) {
                indegree[child]--;
                if (indegree[child] == 0) {
                    que.push(child);
                }
            }
        }

        return result;
    }

    string findOrder(string dict[], int N, int K) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];

            // compare word1 and word2
            for (int j = 0; j < min(word1.size(), word2.size()); j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> result = kahnsAlgorithm(adj);
        string finalResult = "";

        for (int &node : result) {
            finalResult += (node + 'a');
        }

        return finalResult;
    }
};


// Approach 2: DFS (topological sort)
class SolutionDFS {
   public:
    stack<int> st;
    vector<bool> visited;
    void DFS(int curr, unordered_map<int, vector<int>> &adj) {
        visited[curr] = true;

        for (auto &x : adj[curr]) {
            if (!visited[x]) {
                DFS(x, adj);
            }
        }

        // push all childs first -> DFS gurantees this
        // then push parent
        st.push(curr);
    }
    vector<int> topoSort(int V, unordered_map<int, vector<int>> &adj) {
        visited.resize(V, false);
        vector<int> result;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, adj);
            }
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }

    string findOrder(string dict[], int N, int K) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];

            // compare word1 and word2
            for (int j = 0; j < min(word1.size(), word2.size()); j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }

        vector<int> result = topoSort(K, adj);
        string finalResult = "";

        for (int &node : result) {
            finalResult += (node + 'a');
        }

        return finalResult;
    }
};

int main() {
    string a = "abcd";
    string b = "abcd";
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    Solution sol;
    cout << sol.findOrder(dict, 5, 4) << endl;
}