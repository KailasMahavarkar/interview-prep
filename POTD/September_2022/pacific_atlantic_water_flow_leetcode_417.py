from typing import List


class Solution:
    @staticmethod
    def getDiff(number, k):
        prev = -1
        while (number > 0):
            rem = number % 10
            number = number // 10
            if prev != -1:
                if abs(rem - prev) != k:
                    return False
            prev = rem
        return True


    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        answer = []
        for x in range(10**(n-1), 10**n):
            if (self.getDiff(x, k)):
                answer.append(x)

        return answer


x = Solution().numsSameConsecDiff(n=7, k=1)
print(x)


print("diff ->", x)