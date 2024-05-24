
from typing import List


def solve(nums: List[int], temp: List[int], idx: int, answer: List[List[int]]):
    if idx == len(nums):
        answer.append(temp[:])
        return

    # exclude
    solve(nums, temp, idx + 1, answer)

    # include
    temp.append(nums[idx])
    solve(nums, temp, idx + 1, answer)
    temp.pop()


def subset_1_recursive(nums: List[int]) -> List[List[int]]:
    nums.sort()
    answer = []
    solve(nums, [], 0, answer)
    return answer


if __name__ == "__main__":
    print(
        subset_1_recursive([1, 2, 3])
    )
