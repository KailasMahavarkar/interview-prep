from typing import List

def solve(result: List[List[int]], nums: List[int], temp: List[int], idx: int, target: int):
    if idx == len(nums): # meaning we must be at end of recursion stack
        if target == 0:
            result.append(temp[:])
        return
    
    solve(result, nums, temp, idx+1, target)

    if nums[idx] <= target:
        temp.append(nums[idx])
        solve(result, nums, temp, idx, target - nums[idx])
        temp.pop()

        
def combination_sum_recursive(arr: List[int], target: int) -> List[List[int]]:
    result = []
    solve(result=result, nums=arr, temp=[], idx=0, target=target)
    return result


if __name__ == "__main__":
    print(
        combination_sum_recursive(arr=[2, 3, 6, 7], target=7)
    )
