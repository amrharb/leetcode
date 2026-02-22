class Solution:
    def binaryGap(self, n: int) -> int:
        str = bin(n)
        m = len(str)
        mx = 0
        last = m
        for i in range(m):
            if str[i] == "1":
                mx = max(mx, i - last)
                last = i
        return mx
