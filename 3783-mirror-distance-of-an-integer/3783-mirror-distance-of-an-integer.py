class Solution:
    def mirrorDistance(self, n: int) -> int:
        s = str(n)
        while len(s) and s[-1] == "0":
            s = s[:-1]
        rev = int(s[::-1])
        return abs(n - rev)
