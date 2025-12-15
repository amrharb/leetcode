class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        sign = [1, -1][dividend < 0]
        return min(2147483647,sign * int(abs(dividend) / divisor))
