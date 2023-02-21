from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # solving for ransomNote
        ransomNote_dict = Counter(ransomNote)
        # solving for magazine
        magazine_dict = Counter(magazine)
        # checking if ransomNote is in magazine
        for key in ransomNote_dict:
            if key not in magazine_dict or ransomNote_dict[key] > magazine_dict[key]:
                return False
        return True


ans = Solution().canConstruct("kaz", "nokia")
print(ans)