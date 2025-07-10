#include <bits/stdc++.h>
using namespace std;

class EulerianSolver {
   private:
    int n;
    vector<vector<int>> adj;
    vector<int> degree;

    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, visited);
            }
        }
    }

    bool isConnected() {
        vector<bool> visited(n, false);
        int start = -1;

        // Find first vertex with non-zero degree
        for (int i = 0; i < n; i++) {
            if (degree[i] > 0) {
                start = i;
                break;
            }
        }

        if (start == -1) return true;  // No edges

        dfs(start, visited);

        // Check if all vertices with edges are visited
        for (int i = 0; i < n; i++) {
            if (degree[i] > 0 && !visited[i]) {
                return false;
            }
        }
        return true;
    }

   public:
    EulerianSolver(int vertices) : n(vertices) {
        adj.resize(n);
        degree.resize(n, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    string checkEulerian() {
        if (!isConnected()) return "Not Eulerian";

        int oddDegree = 0;
        for (int i = 0; i < n; i++) {
            if (degree[i] % 2 == 1) oddDegree++;
        }

        if (oddDegree == 0) return "Eulerian Circuit";
        if (oddDegree == 2) return "Eulerian Path";
        return "Not Eulerian";
    }

    vector<int> findEulerianPath() {
        string type = checkEulerian();
        if (type == "Not Eulerian") return {};

        int startVertex = 0;
        if (type == "Eulerian Path") {
            for (int i = 0; i < n; i++) {
                if (degree[i] % 2 == 1) {
                    startVertex = i;
                    break;
                }
            }
        }

        // Hierholzer's algorithm
        vector<vector<int>> tempAdj = adj;
        stack<int> currPath;
        vector<int> circuit;

        currPath.push(startVertex);
        int currVertex = startVertex;

        while (!currPath.empty()) {
            if (!tempAdj[currVertex].empty()) {
                currPath.push(currVertex);
                int nextVertex = tempAdj[currVertex].back();
                tempAdj[currVertex].pop_back();

                // Remove edge from both sides
                for (auto it = tempAdj[nextVertex].begin(); it != tempAdj[nextVertex].end(); ++it) {
                    if (*it == currVertex) {
                        tempAdj[nextVertex].erase(it);
                        break;
                    }
                }

                currVertex = nextVertex;
            } else {
                circuit.push_back(currVertex);
                currVertex = currPath.top();
                currPath.pop();
            }
        }

        reverse(circuit.begin(), circuit.end());
        return circuit;
    }

    void printPath(const vector<int>& path) {
        if (path.empty()) {
            cout << "No Eulerian path/circuit exists" << endl;
            return;
        }

        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    // Test 1: Eulerian Circuit
    cout << "=== Test 1: Eulerian Circuit ===" << endl;
    EulerianSolver solver1(4);
    solver1.addEdge(0, 1);
    solver1.addEdge(1, 2);
    solver1.addEdge(2, 3);
    solver1.addEdge(3, 0);

    cout << "Type: " << solver1.checkEulerian() << endl;
    cout << "Path: ";
    solver1.printPath(solver1.findEulerianPath());
}