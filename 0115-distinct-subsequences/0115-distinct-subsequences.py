class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)

        @lru_cache(n * m)
        def solve(i, j):
            if j == m:
                return 1
            if i == n:
                return 0
            ret = solve(i + 1, j)
            if s[i] == t[j]:
                ret += solve(i + 1, j + 1)
            return ret

        return solve(0, 0)
