class Solution:
    def strStr(self, haystack: str, needle: str):
        if needle == "":
            return 0
        
        lps = [] * len(needle)
        prevLPS, i = 0, 1

        while i < len(needle):
            if needle[i] == needle[prevLPS]:
                lps[i] = prevLPS + 1
                prevLPS += 1
                i += 1
            else:
                # no prev prefix match .. last suffix
                if prevLPS == 0:
                    lps[i] = 0
                    i += 1
                else:
                    prevLPS = lps[prevLPS - 1]

        i = 0 # pointer for haystack
        j = 0 # pointer for needle

        while i < len(haystack):
            if haystack[i] == needle[j]:
                i, j = i + 1, j + 1
            else:
                if j == 0:
                    i += 1
                else:
                    j = lps[j - 1]

            if j == len(needle):
                return i - len(needle)
        return -1
    


            
print(
    Solution().strStr(
        haystack='AAACAAA',
        needle='AAAC'
    )
)