
class Solution:
    def __init__(self):
        self.num = 4
        
    def isPowerOfFour(self, n: int) -> bool:
        if (n == 1):
            return True
        while(self.num < n):
            self.num = self.num * 4
        
        return self.num == n

print(
    Solution().isPowerOfFour(1)
)