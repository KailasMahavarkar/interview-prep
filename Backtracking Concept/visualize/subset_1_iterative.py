from typing import List

def solve(nums: List[int], temp: List[int], idx: int, answer: List[List[int]]):
    answer.append(temp[:])

    for i in range(idx, len(nums)):
        temp.append(nums[i])
        solve(nums, temp, i + 1, answer)
        temp.pop()


def subset_1_iterative(nums: List[int]) -> List[List[int]]:
    nums.sort()
    answer = []
    solve(nums, [], 0, answer)
    return answer


if __name__ == "__main__":
    print(
        subset_1_iterative([1, 2, 3, 4])
    )
