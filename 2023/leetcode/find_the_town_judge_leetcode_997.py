from collections import defaultdict

class Solution:
    def __init__(self) -> None:
        self.visited = defaultdict(bool)
        self.result = []

    def dfs(self, adj, curr):
        if self.visited[curr]:
            return

        self.visited[curr] = True
        self.result.append(curr)

        for v in adj[curr]:
            if not self.visited[v]:
                self.dfs(adj, v)

    # Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, V, adj):
        self.dfs(adj, 0)
        return self.result


ans = Solution().dfsOfGraph(V=5, adj=[[1,3],[2,3],[3,1]])
print(ans)