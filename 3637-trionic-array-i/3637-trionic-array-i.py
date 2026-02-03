class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        if nums[0] >= nums[1]:
            return False
        n = len(nums)
        cnt = 0
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                if cnt == 1:
                    cnt = 2
            elif nums[i] < nums[i - 1]:
                if cnt == 0:
                    cnt = 1
                elif cnt == 2:
                    return False
            else:
                return False
        return cnt == 2
