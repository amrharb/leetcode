class Solution:
    def minElement(self, nums: List[int]) -> int:
        ans = 36
        for i, num in enumerate(nums):
            total_digit = 0
            while num:
                total_digit += num % 10
                num = num // 10
            ans = min(ans, total_digit)
        return ans
