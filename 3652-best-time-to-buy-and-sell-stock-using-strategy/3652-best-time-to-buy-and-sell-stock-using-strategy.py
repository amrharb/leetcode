class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        n = len(prices)
        pref = [0] * n
        summ = [0] * n
        for i in range(n):
            pref[i] = pref[i - 1] + prices[i]
            summ[i] = summ[i - 1] + strategy[i] * prices[i]
        ans = summ[n - 1]
        for i in range(n - k + 1):
            before = summ[i - 1] if i else 0
            after = summ[n - 1] - summ[i + k - 1]
            middle = pref[i + k - 1] - pref[i + k // 2 - 1]
            ans = max(ans, before + middle + after)
        return ans
