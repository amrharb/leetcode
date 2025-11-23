class Solution:
    def maxBalancedSubarray(self, nums: List[int]) -> int:
        freq = defaultdict(int)
        summ = 0
        xr = 0
        freq[(0, 0)] = -1
        ans = 0
        for i, num in enumerate(nums):
            summ += 1 if num & 1 else -1
            xr ^= num
            if (summ, xr) in freq:
                ans = max(ans, i - freq[(summ, xr)])
            else:
                freq[(summ, xr)] = i
        return ans
