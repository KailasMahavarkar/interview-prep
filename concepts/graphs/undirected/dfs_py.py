from collections import defaultdict
from queue import Queue

class Solution:
    def __init__(self) -> None:
        self.result = []
        self.que = Queue()
        self.visited = defaultdict(bool)

    def dfs(self, adj, curr):
        if self.visited[curr]:
            return

        self.visited[curr] = True
        self.result.append(curr)
        
        for child in adj[curr]:
            if not self.visited[child]:
                self.dfs(adj, child)

    def dfsOfGraph(self, V, adj):
        self.dfs(adj, 0)
        return self.result


answer = Solution().dfsOfGraph(V=4, adj=[[1, 3], [2, 3], [4, 3]])
print(answer)
