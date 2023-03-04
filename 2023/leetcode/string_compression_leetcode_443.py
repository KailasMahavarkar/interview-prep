from typing import List


class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars) - 1
        i = 0
        j = 0

        local = 0

        while (j < n):
            if (chars[j] == chars[i]):
                local += 1
                j += 1
            else:
                local = 0
                i += 1

            print(i, j, local)

        return chars


ans = Solution().compress(
    chars=["a", "a", "a", "b", "b", "b"]
)
print(ans)
