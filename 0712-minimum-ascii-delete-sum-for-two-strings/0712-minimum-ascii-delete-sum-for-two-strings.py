class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n, m = len(s1), len(s2)

        @lru_cache(None)
        def solve(i, j):
            if i == n and j == m:
                return 0
            if i == n:
                return ord(s2[j]) + solve(i, j + 1)
            if j == m:
                return ord(s1[i]) + solve(i + 1, j)
            if s1[i] == s2[j]:
                return solve(i + 1, j + 1)
            return min(ord(s1[i]) + solve(i + 1, j), ord(s2[j]) + solve(i, j + 1))

        return solve(0, 0)
