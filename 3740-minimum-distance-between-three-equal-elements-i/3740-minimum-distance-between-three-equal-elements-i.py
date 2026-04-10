class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        ans = 10 ** 18
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    if nums[i] == nums[j] == nums[k]:
                        ans = min(ans, j - i + k - j + k - i)
        if ans == 10 ** 18:
            return -1
        return ans