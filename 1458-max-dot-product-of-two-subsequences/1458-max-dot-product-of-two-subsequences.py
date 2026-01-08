class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        m = len(nums2)
        dp = defaultdict(int)

        def solve(i, j, take):
            if i == n or j == m:
                if not take:
                    return -(10**18)
                return 0
            if (i, j, take) in dp:
                return dp[(i, j, take)]
            dp[(i, j, take)] = max(
                solve(i + 1, j, take),
                solve(i, j + 1, take),
                nums1[i] * nums2[j] + solve(i + 1, j + 1, True),
            )
            return dp[(i, j, take)]

        return solve(0, 0, False)
