class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [-1] * n
        for i in range(n):
            if nums[i] & 1:
                last = 0
                for j in range(10):
                    if (nums[i] & (1 << j)) == 0:
                        break
                    last = j
                ans[i] = nums[i] ^ (1 << last)
        return ans
