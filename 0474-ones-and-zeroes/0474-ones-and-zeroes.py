class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        @lru_cache(6 * 10**6)
        def solve(i, zeros, ones):
            if zeros < 0 or ones < 0:
                return -(10**5)
            if i == len(strs):
                return 0
            return max(
                solve(i + 1, zeros, ones),
                1 + solve(i + 1, zeros - strs[i].count("0"), ones - strs[i].count("1")),
            )

        return solve(0, m, n)
