class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        sq = set()
        for a in range(1, n + 1):
            sq.add(a * a)
        for a in range(1, n + 1):
            mxB = int(sqrt(n * n - a * a))
            for b in range(1, mxB + 1):
                if a * a + b * b in sq:
                    ans += 1
        return ans
