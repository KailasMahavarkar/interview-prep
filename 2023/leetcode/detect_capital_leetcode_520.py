class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if (word.lower() == word):
            return True

        if (word.upper() == word):
            return True

        return (word[0].capitalize() + word[1:].lower() == word)


ans = Solution().detectCapitalUse(word="leetcode")
print(ans)