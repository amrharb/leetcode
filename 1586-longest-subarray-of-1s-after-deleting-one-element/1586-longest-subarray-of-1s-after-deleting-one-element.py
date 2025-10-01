class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        l, r = 0, 0
        n = len(nums)
        zeros = 0
        ans = 0
        while l < n:
            while r < n and zeros + (nums[r] == 0) < 2:
                zeros += nums[r] == 0
                r += 1
            ans = max(ans, r - l)
            zeros -= nums[l] == 0
            l += 1
        return max(0, ans - 1)
