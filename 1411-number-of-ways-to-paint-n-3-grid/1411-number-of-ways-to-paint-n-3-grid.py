class Solution:
    def numOfWays(self, n: int) -> int:
        mod = 10**9 + 7

        @cache
        def solve(i, j, last):
            if j == 3:
                return solve(i + 1, 0, last)
            if i == n:
                return 1
            ret = 0
            for k in range(3):
                if (not j or last[j - 1] != k) and k != last[j]:
                    new_last = last[0:j] + tuple([k]) + last[j + 1 :]
                    ret += solve(i, j + 1, new_last)
            if ret > mod:
                ret %= mod
            return ret

        last = tuple([3] * 3)
        return solve(0, 0, last)
