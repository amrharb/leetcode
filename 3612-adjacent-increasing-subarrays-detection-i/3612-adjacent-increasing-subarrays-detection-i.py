class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        for i in range(n - 2 * k + 1):
            ok = True
            for j in range(i + 1, i + k):
                if nums[j] <= nums[j - 1]:
                    ok = False
                    break
            for j in range(i + k + 1, i + 2 * k):
                if nums[j] <= nums[j - 1]:
                    ok = False
                    break
            if ok:
                return True
        return False
