from typing import List

def backtrack(nums, start):
    result = []
    if start == len(nums) - 1:
        result.append(nums[:])
        return result
    
    for i in range(start, len(nums)):
        nums[start], nums[i] = nums[i], nums[start]
        sub_permutations = backtrack(nums, start + 1)

        for sub_permutation in sub_permutations:
            result.append(sub_permutation[:])
        
        nums[start], nums[i] = nums[i], nums[start]
    return result

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return backtrack(nums, 0)


if __name__ == "__main__":
    print(
        Solution().permute(
            nums=[1,2,3]
        )
    )