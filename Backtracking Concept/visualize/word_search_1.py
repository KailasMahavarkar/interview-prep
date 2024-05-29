from typing import List

directions = [(-1, 0), (0, -1), (1, 0), (0, 1)]


def find(board: List[List[str]], word: str, i: int, j: int, idx: int, m: int, n: int) -> bool:
    # base case for success
    if idx >= len(word):
        return True

    # base case for failure
    if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[idx]:
        return False

    # backtracking begins
    temp = board[i][j]
    board[i][j] = '#'
    for dir in directions:
        if find(board, word, i + dir[0], j + dir[1], idx + 1, m, n):
            return True
    board[i][j] = temp
    # backtracking ends

    return False


def exist(board: List[List[str]], word: str) -> bool:
    m = len(board)
    n = len(board[0])

    for i in range(m):
        for j in range(n):
            if board[i][j] == word[0]:
                if find(board, word, i, j, 0, m, n):
                    return True

    return False


exist([["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], "ABCCED")