from typing import List

def backtrack(nums, idx):
    global calls
    result = []
    
    if idx == len(nums) - 1:
        result.append(nums[:])
        return result

    for i in range(idx, len(nums)):
        nums[idx], nums[i] = nums[i], nums[idx]
        sub_permutations = backtrack(nums, idx + 1)

        for sub_permutation in sub_permutations:
            result.append(sub_permutation[:])

        nums[idx], nums[i] = nums[i], nums[idx]
    return result


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return backtrack(nums, 0)


if __name__ == "__main__":
    print(
        Solution().permute(
            nums=[1, 2, 3, 4, 5, 6]
        )
    )
