class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        n = len(prices)

        @lru_cache(n)
        def solve(i):
            if i == n:
                return 0
            if prices[i] == prices[i - 1] - 1:
                return 1 + solve(i + 1)
            return 0

        ans = 0
        for i in range(n):
            ans += 1 + solve(i + 1)
        return ans
