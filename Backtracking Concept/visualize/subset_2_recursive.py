from typing import List

def solve(nums: List[int], temp: List[int], idx: int, result: List[int]):
    if idx == len(nums):
        result.append(temp[:])
        return

    # include
    temp.append(nums[idx])
    solve(nums, temp, idx+1, result)
    temp.pop()


    # Decision to not include nums[idx]
    while idx + 1 < len(nums) and nums[idx] == nums[idx + 1]:
        idx += 1
    solve(nums, temp, idx + 1, result)


def subset_2_recursive(arr: List[int]) -> List[List[int]]:
    result = []
    solve(sorted(arr), [], 0, result)
    return result


if __name__ == "__main__":
    print(
        subset_2_recursive(arr=[1, 2, 3])
    )
