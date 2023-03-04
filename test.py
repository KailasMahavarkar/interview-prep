class Solution:

    def deleteHelper(self, word1: str, word2: str, idx: int, count: int):
        if (len(word1) <= 0 or len(word1) > len(word2)):
            return

        if (word1 == word2):
            return

        a = word1
        a = a[:idx] + a[idx+1:]
        self.deleteHelper(a, word2, idx, count+1)

    def insertHelper(self, word1: str, word2: str, idx: int, count: int):
        if (len(word1) <= 0 or len(word1) > len(word2)):
            return -1

        if (word1 == word2):
            return count

        word1 = word1[:idx] + word2[idx] + word1[idx:]
        self.insertHelper(word1, word2, idx+2, count+1)

    def replaceHelper(self, word1: str, word2: str, idx: int, count: int):
        if (len(word1) <= 0 or len(word1) > len(word2)):
            return -1

        word1 = word1.replace(word1[idx], word2[idx], 1)

        if word1 == word2:
            return count
        
        self.replaceHelper(word1, word2, idx+1, count+1)
        print(word1, word2)

    def minDistance(self, word1: str, word2: str) -> int:

        ans = self.replaceHelper(word1, word2, 0, 0)
        print(ans)

# print(c)
# print(b)
Solution().minDistance("zen", "kai")
