class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        m = len(nums2)

        @lru_cache(None)
        def solve(i, j):
            if i == n or j == m:
                return -inf
            return max(
                nums1[i] * nums2[j],
                solve(i + 1, j),
                solve(i, j + 1),
                nums1[i] * nums2[j] + solve(i + 1, j + 1),
            )

        return solve(0, 0)
