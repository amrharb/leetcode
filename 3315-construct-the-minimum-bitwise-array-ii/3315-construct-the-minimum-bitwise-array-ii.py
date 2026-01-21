class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(len(nums)):
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