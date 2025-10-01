class Solution:
    def isSubsequence(self, t: str, s: str) -> bool:
        n, m = len(s), len(t)
        j = 0
        for i in range(n):
            if j < m and s[i] == t[j]:
                j += 1
        return bool(j == m)
