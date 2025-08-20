class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        lastNonZero = -1
        ans = 0
        n = len(nums)
        for end in range(n):
            if nums[end] == 0:
                ans += end - lastNonZero
            else:
                lastNonZero = end
        return ans
