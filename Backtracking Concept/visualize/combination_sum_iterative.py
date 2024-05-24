from typing import List


def solve(result: List[List[int]], nums: List[int], temp: List[int], idx: int, target: int):
    if target == 0:
        result.append(temp[:])
        return

    for i in range(idx, len(nums)):
        if nums[i] <= target:
            temp.append(nums[i])
            solve(result, nums, temp, i, target - nums[i])
            temp.pop()


def combination_sum_iterative(arr: List[int], target: int) -> List[List[int]]:
    result = []
    solve(result=result, nums=arr, temp=[], idx=0, target=target)
    return result


if __name__ == "__main__":
    print(
        combination_sum_iterative(arr=[2, 3, 6, 7], target=7)
    )
