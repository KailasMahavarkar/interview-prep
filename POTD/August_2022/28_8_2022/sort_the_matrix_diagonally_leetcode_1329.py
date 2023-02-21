from collections import defaultdict
from typing import List

class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        pass
        # rows, cols = len(mat), len(mat[0])
        # # d = defaultdict(list)
        # for i in range(rows):
        #     for j in range(cols):
        #         print(mat[i][j])
        #         # d[i - j].append(mat[i][j])



        # print(d)
        
        # for k in d:
        #     d[k].sort(reverse=True)
        # for i in range(m):
        #     for j in range(n):
        #         mat[i][j] = d[i - j].pop()
        # return mat

# Solution().diagonalSort(mat=[[3, 4], [2, 1]])


matrix = [[3,4], [2,1]]
rows = len(matrix)
cols = len(matrix[0])

d = defaultdict(list)
for x in range(rows):
    for y in range(cols):
        d[x-y].append(matrix[x][y])
    
for x in d:
    d[x].sort()

for x in range(rows):
    for y in range(cols):
        matrix[x][y] = d[x-y].pop()

print(matrix)