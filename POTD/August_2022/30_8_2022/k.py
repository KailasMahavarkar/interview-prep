from typing import List

class Solution:
    @staticmethod
    def transpose(matrix):
        N = len(matrix)

        for i in range(N):
            for j in range(i+1, N):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        return matrix

    @staticmethod
    def reverseRows(matrix):
        if len(matrix) <= 0:
            return matrix

        for line in matrix:
            i = 0
            j = len(line) - 1
            while (i < j):
                line[i],line[j]  = line[j], line[i]
                i += 1
                j -= 1

        return matrix

    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        return self.reverseRows(self.transpose(matrix))
        

x = Solution().rotate([])
print(x)