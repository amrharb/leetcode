class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        minVal = [0] * k
        pref = 0
        for i in range(k):
            pref += nums[i]
            minVal[i] = pref
        minVal[k - 1] = min(minVal[k - 1], 0)
        n = len(nums)
        ans = pref
        for i in range(k, n):
            pref += nums[i]
            idx = i % k
            ans = max(ans, pref - minVal[idx])
            minVal[idx] = min(minVal[idx], pref)
        return ans
