class Solution:
    def numberOfWays(self, s: str) -> int:
        n = len(s)
        mod = 10**9 + 7

        @lru_cache
        def solve(i, cnt):
            if cnt > 2:
                return 0
            if i == n:
                return cnt == 2
            return (
                solve(i + 1, cnt + (s[i] == "S"))
                + (solve(i + 1, 0) if cnt + (s[i] == "S") == 2 else 0)
            ) % mod

        return solve(0, 0)
