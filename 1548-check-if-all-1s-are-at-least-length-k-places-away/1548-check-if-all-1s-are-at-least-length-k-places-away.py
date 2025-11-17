class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        last = -k-1
        n = len(nums)
        for i in range(n):
            if nums[i] == 1:
                if i - last <= k:
                    return False
                last = i
        return True