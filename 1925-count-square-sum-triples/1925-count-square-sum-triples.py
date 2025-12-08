class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0

        def IsPerfectSquare(n):
            sq = int(sqrt(n))
            return sq * sq == n

        sq = {}
        squares = []
        for a in range(1, n + 1):
            squares.append(a * a)
            sq[a * a] = 1
        for a in squares:
            for b in squares:
                if a + b in sq:
                    ans += 1
        return ans
