class Solution:
    def solve(self, matrix) -> None:
        res = float('-inf')
        rows = len(matrix)
        cols = len(matrix[0])

        sumArr = []

        l = 0
        r = 0

        for x in range(cols):
            print(x)

        print(rows, cols)

Solution().solve(matrix=[[1,2,3], [4, 5, 6]])
