from collections import Counter
from pprint import pprint as log
from time import sleep

# time complexity -> O(n)
# space complexity -> O(1)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0 # stable pointer
        r = 0 # changing pointer
        mapp = {}
        ans = 0
        while (r < len(s)):
            # teleport [l] to value from map
            if s[r] in mapp:
                l = max(mapp[s[r]] + 1, l)

            # update mapp to current right
            mapp[s[r]] = r

            # computer answer and maximum
            ans = max(ans, r-l +1)
            r+=1

        print(ans)
        return ans


Solution().lengthOfLongestSubstring("abba")
