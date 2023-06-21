from collections import defaultdict

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:

        s = s.split()

        if (len(s) != len(pattern)):
            return False

        aMap = defaultdict(str)
        bMap = defaultdict(str)

        for i, e in enumerate(s.split()):
            aMap[pattern[i]] = e
            bMap[e] = pattern[i]

        c1 = list(aMap.keys()) == list(bMap.values())
        c2 = list(aMap.values()) == list(bMap.keys())
        return (c1 and c2)
        # return (aMap.keys() == bMap.values() and aMap.values() == bMap.keys())


ans = Solution().wordPattern(pattern="abba", s="fish cat cat fish")
print(ans)