class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        ans = n - 1
        for i in range(n):
            ans = min(ans, i + n - bisect_right(nums, nums[i] * k))
        return ans
