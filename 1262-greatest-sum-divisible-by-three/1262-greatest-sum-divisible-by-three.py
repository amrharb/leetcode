class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [[-(10**9) for _ in range(3)] for _ in range(n + 1)]
        dp[n][0] = 0
        for i in range(n - 1, -1, -1):
            for rem in range(3):
                dp[i][rem] = max(
                    dp[i + 1][rem], nums[i] + dp[i + 1][(rem + nums[i]) % 3]
                )
        return dp[0][0]
