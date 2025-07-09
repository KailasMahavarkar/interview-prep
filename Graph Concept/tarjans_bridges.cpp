#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class BridgeFinder {
   private:
    int n;                    // number of vertices
    vector<vector<int>> adj;  // adjacency list
    vector<int> discovery, low, parent;
    vector<pair<int, int>> bridges;
    int timer;

    void bridgeUtil(int u) {
        // initially both low and discovery is set to new tick of timer
        timer++;

        // lowest we can reach is that node (we dont know future nodes)
        low[u] = timer;
        discovery[u] = timer;

        // from that node -> visit childrens
        for (auto& v : adj[u]) {
            // if child is not visited then only we visit
            if (discovery[v] == -1) {
                // since we visit 'v' from 'u' -> we mark that as parent
                parent[v] = u;

                bridgeUtil(v);

                // when dfs returns we check 2 things
                // 1. should we update lowlink
                // 2. have we found bridge?
                low[u] = min(low[v], low[u]);

                if (low[v] > discovery[u]) {
                    bridges.push_back({v, u});
                }
            }

            if (discovery[v] != -1 && v != parent[u]) {  // is v where i came from to u? camefrom = parent
                // we update the low link for parent
                low[u] = min(low[u], discovery[v]);
            }
        }
    }

   public:
    BridgeFinder(int vertices) : n(vertices) {
        adj.resize(n);
        discovery.resize(n, -1);
        low.resize(n);
        parent.resize(n);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }

    vector<pair<int, int>> findBridges() {
        // Initialize arrays
        fill(parent.begin(), parent.end(), -1);
        bridges.clear();
        timer = 0;

        // Call the recursive helper function for all vertices
        for (int i = 0; i < n; i++) {
            if (discovery[i] == -1) {
                bridgeUtil(i);
            }
        }

        return bridges;
    }

    void printGraph() {
        cout << "Graph adjacency list:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    void printBridges(const vector<pair<int, int>>& bridges) {
        cout << "\nBridges found:\n";
        if (bridges.empty()) {
            cout << "No bridges found.\n";
        } else {
            for (const auto& bridge : bridges) {
                cout << "Bridge: " << bridge.first << " - " << bridge.second << "\n";
            }
        }
        cout << "Total bridges: " << bridges.size() << "\n";
    }
};

int main() {
    cout << "Example 1: Simple bridge" << endl;
    BridgeFinder graph1(4);
    // 0 --- 2
    // |    /
    // |   /
    // 1 ----- 3
    graph1.addEdge(0, 2);
    graph1.addEdge(0, 1);
    graph1.addEdge(1, 2);
    graph1.addEdge(1, 3);

    graph1.printGraph();
    vector<pair<int, int>> bridges1 = graph1.findBridges();
    graph1.printBridges(bridges1);

    return 0;
}
