from pprint import pprint


matrix = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8]
]

rows = len(matrix)
cols = len(matrix[0])

result = [[0]*rows for _ in range(cols)]


for i in range(rows):
    for j in range(cols):
        result[j][i] = matrix[i][j]

print(*result, sep="\n")
