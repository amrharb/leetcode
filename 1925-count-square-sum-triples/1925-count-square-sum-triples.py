class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0

        def IsPerfectSquare(n):
            sq = int(sqrt(n))
            return sq * sq == n

        for a in range(1, n + 1):
            b = 1
            while a * a + b * b <= n * n:
                if IsPerfectSquare(a * a + b * b):
                    ans += 1
                b += 1
        return ans
