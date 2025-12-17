class Solution:
    def maximumProfit(self, p: List[int], k: int) -> int:
        n = len(p)
        dp = [[-(10**18) for _ in range(3)] for _ in range(k + 2)]
        for i in range(k + 1):
            dp[i][2] = 0
        for i in range(n):
            for rem in range(0, k + 1):
                dp[rem][2] = max(dp[rem][2], dp[rem][0] - p[i], dp[rem][1] + p[i])
                dp[rem][0] = max(dp[rem][0], dp[rem + 1][2] + p[i])
                dp[rem][1] = max(dp[rem][1], dp[rem + 1][2] - p[i])
        return dp[0][2]
