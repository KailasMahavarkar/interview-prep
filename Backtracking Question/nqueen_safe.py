board = [
    ". . . . .",  # 0
    ". . . . .",  # 1
    ". . . . .",  # 2
    ". . . . .",  # 3
    ". . . . ."  # 4
]
N = len(board)


def isSafe(board, row, col):
    # check if there is only one queen in the row
    if board[row].count("Q") > 1:
        return False

    # check if there is a queen in the same column
    if [x[col] for x in board].count("Q") > 1:
        return False


    i = row
    j = col
    while i >= 0 and j >= 0:
        if (board[i][j] == 'Q'):
            return False
        i -= 1
        j -= 1

    i = row
    j = col
    while i >= 0 and j < N:
        if (board[i][j] == 'Q'):
            return False
        i -= 1
        j += 1

    return True


# (1, 0) (2, 1) (3, 2), (4, 3)
board = [x.replace(" ", "") for x in board]

print(
    isSafe(board=board, row=4, col=0)
)
# print(board[1][0])
# print(board[2][1])
# print(board[3][2])
# print(board[4][3])
