class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(p), len(s)

        @lru_cache
        def match(i, j):
            if i == n:
                return j == m
            if j == m:
                if i + 1 < n and p[i + 1] == "*":
                    return match(i + 2, j)
                return False
            if (p[i] == s[j] or p[i] == ".") and (i + 1 == n or p[i + 1] != "*"):
                return match(i + 1, j + 1)
            if i + 1 < n and p[i + 1] == "*":
                if match(i + 2, j):
                    return True
                for k in range(j, m):
                    if s[k] == p[i] or p[i] == ".":
                        if match(i + 2, k + 1):
                            return True
                    else:
                        break
            return False

        return match(0, 0)
