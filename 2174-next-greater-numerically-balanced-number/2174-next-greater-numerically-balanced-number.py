from itertools import permutations
from bisect import bisect_right


class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        m = len(str(n))
        ans = []
        def solve(d, cur):
            if d == 10:
                if len(cur) >= m:
                    for p in set(permutations(cur)):
                        if p[0] == "0":
                            continue
                        ans.append(int("".join(p)))
                return
            solve(d + 1, cur)
            if len(cur) + d <= m + 1:
                solve(d + 1, cur + str(d) * d)

        solve(1, "")
        ans.sort()
        idx = bisect_right(ans, n)
        return ans[idx]
