class Solution:
    def numberOfWays(self, s: str) -> int:
        n = len(s)
        mod = 10**9 + 7

        dp = [[-1 for _ in range(3)] for _ in range(n)]

        def solve(i, cnt):
            if cnt > 2:
                return 0
            if i == n:
                return cnt == 2
            if dp[i][cnt] != -1:
                return dp[i][cnt]
            dp[i][cnt] = (
                solve(i + 1, cnt + (s[i] == "S"))
                + (solve(i + 1, 0) if cnt + (s[i] == "S") == 2 else 0)
            ) % mod
            return dp[i][cnt]

        return solve(0, 0)
