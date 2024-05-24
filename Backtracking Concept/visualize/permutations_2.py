from typing import List

# This code works for both permutations 1 and 2
def backtrack(result, nums, idx):
    if idx == len(nums) - 1:
        result.append(nums[:])
        return

    myset = set()

    for i in range(idx, len(nums)):
        if nums[i] not in myset:
            nums[i], nums[idx] = nums[idx], nums[i]
            backtrack(idx=idx+1, nums=nums, result=result)
            nums[i], nums[idx] = nums[idx], nums[i]
            myset.add(nums[i])


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = []
        backtrack(result, nums, 0)
        return result


if __name__ == "__main__":
    print(
        Solution().permuteUnique(
            nums=[1, 2, 2]
        )
    )
