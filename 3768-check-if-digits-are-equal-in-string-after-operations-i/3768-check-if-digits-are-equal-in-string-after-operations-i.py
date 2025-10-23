class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)
        while n > 2:
            nw = ""
            for i in range(1, n):
                nw += chr(
                    (int(ord(s[i]) - ord("0")) + int(ord(s[i - 1]) - ord("0"))) % 10
                    + ord("0")
                )
            s = nw
            n -= 1
        return s[0] == s[1]
