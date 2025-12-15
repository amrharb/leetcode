class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        n = len(prices)
        prev = 0
        ans = 0
        for i in range(n):
            if not i or prices[i] == prices[i - 1] - 1:
                prev += 1
            else:
                prev = 1
            ans += prev
        return ans
