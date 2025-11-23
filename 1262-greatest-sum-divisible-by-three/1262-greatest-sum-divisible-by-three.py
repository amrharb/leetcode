class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        @lru_cache(12 * 10**4)
        def solve(i, rem):
            if i == len(nums):
                if rem == 0:
                    return 0
                return -(10**9)
            return max(solve(i + 1, rem), nums[i] + solve(i + 1, (rem + nums[i]) % 3))

        return solve(0, 0)
