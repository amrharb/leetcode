class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazine = "".join(sorted(magazine))
        ransomNote = "".join(sorted(ransomNote))
        i = j = 0
        n, m = len(ransomNote), len(magazine)
        for i in range(m):
            if j < n and ransomNote[j] == magazine[i]:
                j += 1
        return bool(j == n)
