from collections import defaultdict
from email.policy import default
from pprint import pprint
from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def gridNotSafe(i, j):
            return i < 0 or j < 0 or i == len(grid) or j == len(grid[0])

        def dfs(i, j):
            if gridNotSafe(i, j) or grid[i][j] == "0":
                return

            # mark visited
            grid[i][j] = "0"

            dfs(i, j+1)
            dfs(i, j-1)
            dfs(i+1, j)
            dfs(i-1, j)
            return
            
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    res += 1
                    dfs(i, j)
        return res


# grid = [
#     ["1", "1", "0", "0", "0"],
#     ["1", "1", "0", "0", "0"],
#     ["0", "0", "1", "0", "0"],
#     ["0", "0", "0", "1", "1"]
# ]

# x = Solution().numIslands(grid)
# print(x)


class Solution:
    def pacificAtlantic(self, M: List[List[int]]) -> List[List[int]]:
        maxRows = len(M)
        maxCols = len(M[0])
        visited = defaultdict(dict)
        count = 0

        def isNotSafe(i, j):
            return i < 0 or j < 0 or i == maxRows or j == maxCols

        def dfs(i, j):
            # base case
            if isNotSafe(i, j) or visited[i, j] == 1:
                return

            # process cell
            visited[i][j] = 1
            
            # dfs calls
            dfs(i, j+1)
            dfs(i+1, j+1)
            dfs(i+1, j)
            dfs(i+1, j-1)
            dfs(i, j-1)
            return

        for x in range(maxRows):
            for y in range(maxCols):
                count += 1
                dfs(x, y)
        print(count)


matrix = [
    [1, 2, 2, 3, 5],
    [3, 2, 3, 4, 4],
    [2, 4, 5, 3, 1],
    [6, 7, 1, 4, 5],
    [5, 1, 1, 2, 4]
]


Solution().pacificAtlantic(M=matrix)
