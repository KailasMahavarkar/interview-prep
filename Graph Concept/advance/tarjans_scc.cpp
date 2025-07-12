#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class TarjanSCC {
   private:
    int n;                           // number of vertices
    vector<vector<int>> adj;         // adjacency list (directed graph)
    vector<int> discovery, lowlink;  // discovery time and low-link value
    vector<bool> inStack;            // to check if vertex is in stack
    stack<int> st;                   // stack to store vertices
    vector<vector<int>> sccs;        // to store all SCCs
    int timer;                       // global timer for discovery time

    void sccUtil(int u) {
        timer++;

        // i just visited the node so its discovery and low time is current timer
        discovery[u] = timer;
        lowlink[u] = timer;

        // push current parent to stack
        st.push(u);
        inStack[u] = true;

        for (auto& v : adj[u]) {
            // we have seen this node for 1st time
            if (discovery[v] == -1) {
                sccUtil(v);

                // when recursion rolls we update backlink
                lowlink[u] = min(lowlink[u], lowlink[v]);
            }

            if (discovery[v] != -1 && inStack[v]) {
                // Stack proves:    v ——→ u  (tree path) (v came first then u (u is current, v was already in stack))
                // We discovered:   u ——→ v  (direct edge)
                // Result:          v ——→ u ——→ v  (CYCLE!)
                lowlink[u] = min(lowlink[u], discovery[v]);
            }
        }

        // we are at root 
        if (lowlink[u] == discovery[u]){
            vector<int> scc;

            while(true){
                int w = st.top();
                st.pop();
                inStack[w] = false;
                scc.push_back(w);
                
                if (w == u) break;
            }

            sort(scc.begin(), scc.end());
            sccs.push_back(scc);
        }
    }

   public:
    TarjanSCC(int vertices) : n(vertices) {
        adj.resize(n);
        discovery.resize(n);
        lowlink.resize(n);
        inStack.resize(n);
        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);  // Directed edge from u to v
    }

    vector<vector<int>> findSCCs() {
        // Initialize arrays
        fill(discovery.begin(), discovery.end(), -1);
        fill(lowlink.begin(), lowlink.end(), -1);
        fill(inStack.begin(), inStack.end(), false);

        // Clear stack and results
        while (!st.empty()) st.pop();
        sccs.clear();
        timer = 0;

        // Call the recursive helper function for all vertices
        for (int i = 0; i < n; i++) {
            if (discovery[i] == -1) {
                sccUtil(i);
            }
        }

        // Sort SCCs by their first element for consistent output
        sort(sccs.begin(), sccs.end());
        return sccs;
    }

    void printGraph() {
        cout << "Directed graph adjacency list:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }

    void printSCCs(const vector<vector<int>>& sccs) {
        cout << "\nStrongly Connected Components:\n";
        if (sccs.empty()) {
            cout << "No SCCs found (empty graph).\n";
        } else {
            for (int i = 0; i < sccs.size(); i++) {
                cout << "SCC " << i + 1 << ": { ";
                for (int j = 0; j < sccs[i].size(); j++) {
                    cout << sccs[i][j];
                    if (j < sccs[i].size() - 1) cout << ", ";
                }
                cout << " }\n";
            }
        }
        cout << "Total SCCs: " << sccs.size() << "\n";
    }
};

int main() {
    // Example usage
    TarjanSCC graph(5);

    // Add directed edges
    graph.addEdge(1, 0);
    graph.addEdge(0, 2);
    graph.addEdge(2, 1);  // SCC: {0, 1, 2}
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);  // Individual SCCs: {3}, {4}

    graph.printGraph();

    vector<vector<int>> sccs = graph.findSCCs();
    graph.printSCCs(sccs);

    return 0;
}
