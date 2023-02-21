
from typing import List
from queue import Queue
from collections import defaultdict


class Solution:
    def __init__(self):
        self.result = []
        self.visited = defaultdict(bool)

    #Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, V: int, adj: List[List[int]]) -> List[int]:
        queue = Queue(V)
        queue.put(0)
        self.visited[0] = True
        self.result.append(0) 
        
        while (not queue.empty()):
            parent = queue.get()

            for child in adj[parent]:
                if (not self.visited[child]):
                    queue.put(child)
                    self.visited[child] = True
                    self.result.append(child)
        
        return self.result



ans = Solution().bfsOfGraph(V=4, adj=[[1,3], [0,2], [1, 3], [2, 0]])
print(ans)