from typing import List

def solve(answer:List[List[int]], nums: List[int], idx: int):
    if idx >= len(nums):
        answer.append(nums[:])
        return
    
    for i in range(idx, len(nums)):
        nums[idx], nums[i] = nums[i], nums[idx]
        solve(answer, nums, idx + 1)
        nums[idx], nums[i] = nums[i], nums[idx]


def permute(nums: List[int]) -> List[List[int]]:
    answer = []
    solve(answer, nums, 0)
    return answer


if __name__ == "__main__":
    print(
        permute(
            nums=[1,2,3]
        )
    )