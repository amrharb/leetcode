class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            for j in range(max(i - 5, 0), i):
                if nums[i] == nums[j]:
                    return nums[i]
        return -1
