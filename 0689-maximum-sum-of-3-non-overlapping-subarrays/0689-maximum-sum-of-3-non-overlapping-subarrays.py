class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        for i in range(1, n):
            nums[i] += nums[i - 1]
        
        @lru_cache(None)
        def solve(i, taken):
            if taken == 3:
                return 0
            if i + k - 1 >= n:
                return -(10**18)
            ret = max(
                solve(i + 1, taken),
                nums[i + k - 1] - (nums[i - 1] if i else 0) + solve(i + k, taken + 1),
            )
            return ret

        print(solve(0, 0))
        ans = []

        def build(i, taken):
            if taken == 3:
                return
            if i + k - 1 >= n:
                return
            if nums[i + k - 1] - (nums[i - 1] if i else 0) + solve(
                i + k, taken + 1
            ) == solve(i, taken):
                ans.append(i)
                build(i + k, taken + 1)
                return
            build(i + 1, taken)

        build(0, 0)
        return ans
