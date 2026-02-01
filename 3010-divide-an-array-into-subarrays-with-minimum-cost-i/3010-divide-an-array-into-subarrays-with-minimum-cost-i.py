class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        cost = nums[0]
        nums.pop(0)
        nums.sort()
        return cost + nums[0] + nums[1]
