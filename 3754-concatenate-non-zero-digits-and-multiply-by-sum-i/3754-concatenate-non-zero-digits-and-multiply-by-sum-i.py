class Solution:
    def sumAndMultiply(self, n: int) -> int:
        summ = 0
        x = 0
        s = str(n)
        for ch in s:
            summ += ord(ch) - ord("0")
            if ch != "0":
                x = x * 10 + ord(ch) - ord("0")
        return x * summ
