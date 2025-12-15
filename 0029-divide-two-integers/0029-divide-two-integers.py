class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        sign = [1, -1][dividend < 0] * [1, -1][divisor < 0]
        return min(2**31 - 1, sign * int(abs(dividend) // abs(divisor)))
