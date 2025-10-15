class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        nums.append(-2 * 10**9)
        suf = [1] * (n + 1)
        for i in range(n - 1, -1, -1):
            suf[i] = suf[i + 1] + 1 if nums[i] < nums[i + 1] else 1
        ans = max(suf) // 2
        for i in range(n):
            ans = max(ans, min(suf[i], suf[i + suf[i]]))
        return ans
