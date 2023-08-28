from typing import List

class Solution:
    def pacificAtlantic(self, M: List[List[int]]) -> List[List[int]]:
        maxRows = len(M)
        maxCols = len(M[0])

        pacific = [[x for x in range(maxCols)] for _ in range(maxRows)]
        atlantic = [[x for x in range(maxCols)] for _ in range(maxRows)]


        def dfs(M, i, j, prev, ocean):
            if i == maxRows or i < 0 or j == maxCols or j < 0:
                return
            
            if M[i][j]  < prev:
                return 
            
            if ocean[i][j] == -1:
                return
            
            # process cell
            ocean[i][j] = -1
            
            # dfs calls
            dfs(M, i+1, j, M[i][j], ocean)
            dfs(M, i-1, j, M[i][j], ocean)
            dfs(M, i, j+1, M[i][j], ocean)
            dfs(M, i, j-1, M[i][j], ocean)
        
        # for top and bottom
        for col in range(maxCols):
            dfs(M, 0,           col, float('-inf'), pacific)
            dfs(M, maxRows - 1, col, float('-inf'), atlantic)

        # for left and right
        for row in range(maxRows):
            dfs(M, row, 0,           float('-inf'), pacific)
            dfs(M, row, maxCols - 1, float('-inf'), atlantic)


        answer = []

        for x in range(maxRows):
            for y in range(maxCols):
                if pacific[x][y] == atlantic[x][y] and pacific[x][y] == -1:
                    answer.append([x, y])
        
        return answer


testcase1 = [
    [1, 2, 2, 3, 5],
    [3, 2, 3, 4, 4],
    [2, 4, 5, 3, 1],
    [6, 7, 1, 4, 5],
    [5, 1, 1, 2, 4]
]

testcase2 = [
    [1, 2, 3],
    [4, 5, 6],
    [9, 8, 7]
]

x = Solution().pacificAtlantic(
    M=testcase2
)

print(x)
