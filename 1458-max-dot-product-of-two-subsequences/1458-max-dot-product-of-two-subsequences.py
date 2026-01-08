class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        m = len(nums2)

        @cache
        def solve(i, j, take):
            if i == n or j == m:
                if not take:
                    return -inf
                return 0
            return max(
                solve(i + 1, j, take),
                solve(i, j + 1, take),
                nums1[i] * nums2[j] + solve(i + 1, j + 1, True),
            )

        return solve(0, 0, False)
