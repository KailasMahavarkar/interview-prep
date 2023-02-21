from collections import defaultdict

class Solution:
    def __init__(self) -> None:
        self.visited = defaultdict(bool)
        self.stack = []
    
    def dfs(self, adj, curr):
        if self.visited[curr]:
            return
        
        self.visited[curr] = True

        for child in adj[curr]:
            if not self.visited[curr]:
                self.dfs(adj=adj, curr=child)
            
        self.stack.append(curr)


    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        for i in range(0, len(adj)):
            if (not self.visited[i]):
                self.dfs(adj, i)
        
        self.stack.reverse()
        return self.stack


ans = Solution().topoSort(V=3, adj=[
    [3, 2], 
    [1, 3]
])

print(ans)