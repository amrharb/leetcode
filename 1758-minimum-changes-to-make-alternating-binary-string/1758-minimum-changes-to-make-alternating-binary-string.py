class Solution:
    def minOperations(self, s: str) -> int:
        def solve(i, curr):
            if i == len(s):
                return 0
            return (chr(curr + ord("0")) != s[i]) + solve(i + 1, curr ^ 1)

        return min(solve(0, 0), solve(0, 1))
