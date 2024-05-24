from typing import List

def backtrack(temp, nums, result, st):
    if len(temp) == len(nums):
        result.append(temp[:])
        return

    for num in nums:
        if num not in st:
            temp.append(num)
            st.add(num)
            backtrack(temp, nums, result, st)
            st.remove(num)
            temp.pop()


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        backtrack([], nums, result, set())
        return result



if __name__ == "__main__":
    print(
        Solution().permute(
            nums=[1, 2, 3]
        )
    )
