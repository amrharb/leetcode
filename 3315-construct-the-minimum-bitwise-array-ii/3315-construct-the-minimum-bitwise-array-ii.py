class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [-1] * n
        for i in range(n):
            if nums[i] & 1:
                d = 1
                last = 0
                while nums[i] & d:
                   last = d
                   d <<= 1
                nums[i] -= last
            else:
                nums[i] = -1
        return nums