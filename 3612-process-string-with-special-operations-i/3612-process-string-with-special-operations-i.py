class Solution:
    def processStr(self, s: str) -> str:
        res = ""
        for ch in s:
            if ch.islower():
                res += ch
            elif ch == '*':
                if res:
                    res = res[:-1]
            elif ch == '#':
                res += res
            else:
                res = res[::-1]
        return res