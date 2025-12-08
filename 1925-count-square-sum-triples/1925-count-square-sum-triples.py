class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        sq = {}
        for a in range(1, n + 1):
            sq[a * a] = 1
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                if a * a + b * b in sq:
                    ans += 1
                elif a * a + b * b > n * n:
                    break
        return ans
