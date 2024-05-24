from typing import List

def solve(nums: List[int], temp: List[int], idx: int, result: List[int]):
    result.append(temp[:])

    for i in range(idx, len(nums)):
        if i > idx and nums[i] == nums[i - 1]:
            continue
        temp.append(nums[i])
        solve(nums, temp, i+1, result)
        temp.pop()


def subset_2_iterative(arr: List[int]) -> List[List[int]]:
    result = []
    solve(sorted(arr), [], 0, result)
    return result


if __name__ == "__main__":
    print(
        subset_2_iterative(arr=[1, 2, 3])
    )
