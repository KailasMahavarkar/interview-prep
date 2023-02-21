from collections import defaultdict
from typing import List


class Solution:
    def __init__(self) -> None:
        self.visited = defaultdict(bool)
        self.in_recursion = defaultdict(bool)

    def isCycleDFS(self, adj, curr) -> bool:

        if (self.visited[curr]):
            return

        self.visited[curr] = True
        self.in_recursion[curr] = True

        for child in adj[curr]:
            if (self.visited[child]):
                if (self.in_recursion[child]):
                    return True
            else:
                if (self.isCycleDFS(adj=adj, curr=child)):
                    return True

        self.in_recursion[curr] = False
        return False

    def isCyclic(self, V: int, adj: List[List[int]]) -> bool:
        for i in range(0, V):
            if not self.visited[i] and self.isCycleDFS(adj, i):
                return True

        return False


ans = Solution().isCyclic(V=5, adj=[[1], [2], [3, 4], [1], []])
print(ans)
