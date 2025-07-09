#include <bits/stdc++.h>
using namespace std;

class Solutions {
   private:
    int n;
    vector<vector<int>> graph;  // why adj matrix? -> at every point we need check if we have edge or not thus
    vector<int> path;
    vector<bool> visited;

    bool hamiltonianUtil(int pos, bool isCircuit, int start) {
        if (pos == n) {
            return isCircuit ? graph[path[pos - 1]][start] == 1 : true;
        }

        for (int v = 0; v < n; v++) {
            if (graph[path[pos - 1]][v] == 1 && !visited[v]) {
                path[pos] = v;
                visited[v] = true;

                if (hamiltonianUtil(pos + 1, isCircuit, start)) {
                    return true;
                }

                path[pos] = -1;
                visited[v] = false;
            }
        }
        return false;
    }

   public:
    Solutions(int vertices) : n(vertices) {
        graph.resize(n, vector<int>(n, 0));
        path.resize(n, -1);
        visited.resize(n, false);
    }

    void addEdge(int u, int v) {
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    bool hamiltonianPath(int start = 0) {
        fill(path.begin(), path.end(), -1);
        fill(visited.begin(), visited.end(), false);

        path[0] = start;
        visited[start] = true;

        return hamiltonianUtil(1, false, start);
    }

    bool hamiltonianCircuit(int start = 0) {
        fill(path.begin(), path.end(), -1);
        fill(visited.begin(), visited.end(), false);

        path[0] = start;
        visited[start] = true;

        return hamiltonianUtil(1, true, start);
    }

    void printPath() {
        for (int i = 0; i < n; i++) {
            cout << path[i];
            if (i < n - 1) cout << " -> ";
        }
        cout << endl;
    }

    void printCircuit(int start) {
        printPath();
        cout << "Circuit: ";
        for (int i = 0; i < n; i++) {
            cout << path[i] << " -> ";
        }
        cout << start << endl;
    }

    void displayGraph() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solutions sol4(6);
    sol4.addEdge(0, 1);
    sol4.addEdge(1, 2);
    sol4.addEdge(2, 3);
    sol4.addEdge(3, 4);
    sol4.addEdge(4, 5);
    sol4.addEdge(5, 0);
    sol4.addEdge(1, 4);
    sol4.addEdge(2, 5);

    sol4.displayGraph();
    if (sol4.hamiltonianPath()) {
        cout << "Hamiltonian Path: ";
        sol4.printPath();
    }
    if (sol4.hamiltonianCircuit()) {
        cout << "Hamiltonian Circuit: ";
        sol4.printCircuit(0);
    }

    return 0;
}