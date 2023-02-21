from typing import List


def print_matrix(matrix: List[List[int]]):
    for i in matrix:
        for j in i:
            print(j, end=' ')
        print()
    print('-----')


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        max_cols = len(matrix)
        max_rows = len(matrix[0])


        for r in range(0, max_cols):
            for c in range(0, max_rows):
                if (matrix[r][c] == 0):
                    # meaning we are not at 1st row
                    
                    temp = r
                    while (temp - 1 > 0):
                        temp -= 1
                        matrix[temp][c] = 0
                
                # if (c - 1 > 0):
                #     temp = c
                #     while (temp - 1 > 0):
                #         temp -= 1
                #         matrix[r][temp] = 0


        print_matrix(matrix)
        return matrix


ans = Solution().setZeroes([
    [1, 2, 3], 
    [4, 2, 0], 
    [7, 8, 9]
])

# print_matrix(ans)