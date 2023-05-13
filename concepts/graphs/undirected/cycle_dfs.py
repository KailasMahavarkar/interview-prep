from typing import List
from collections import defaultdict


class Solution:
    def __init__(self) -> None:
        self.visited = defaultdict(bool)
        
    def isCycleDFS(self, adj, curr, parent):
        self.visited[curr] = True
  
        for child in adj[curr]:
            if (child == parent):
                continue

            if (self.visited[child]):
                return True
            if (self.isCycleDFS(adj=adj, curr=child, parent=curr)):
                return True
        return False

    def isCycle(self, V: int, adj: List[List[int]]) -> bool:
        for i in range(0, V):
            if not self.visited[i] and self.isCycleDFS(adj, i, -1):
                return True
        return False


ans = Solution().isCycle(V=5, adj=[[1], [0, 2, 4], [1, 3], [2, 4], [1, 3]])
print(ans)
