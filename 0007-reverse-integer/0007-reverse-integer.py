class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        s = str(abs(x))
        while len(s) > 1 and s[-1] == "0":
            s = s[:-1]
        s = s[::-1]

        def normalize(x):
            return x if x in range(-(2**31), 2**31) else 0

        return normalize(sign * int(s))
