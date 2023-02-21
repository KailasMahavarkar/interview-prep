from collections import defaultdict

class Solution:
    def __init__(self) -> None:
        self.visited = defaultdict(bool)
        self.stack = []
    
    def dfs(self, adj, curr):
        
        self.visited[curr] = True

        for child in adj[curr]:
            if not self.visited[child]:
                self.dfs(adj=adj, curr=child)
            
        self.stack.append(curr)


    #Function to return list containing vertices in Topological order.
    def topoSort(self, V, adj):
        for i in range(0, len(adj)):
            if (not self.visited[i]):
                self.dfs(adj, i)

        result = []
        while(len(self.stack) > 0):
            peek = self.stack[-1]
            result.append(peek)
            self.stack.pop(-1)

        return result







ans = Solution().topoSort(V=4, adj=[[0], [], [0], [0]])
print(ans)
