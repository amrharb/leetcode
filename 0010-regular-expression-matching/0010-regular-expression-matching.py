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
            first_match = p[i] == s[j] or p[i] == "."
            if i + 1 < n and p[i + 1] == "*":
                return match(i + 2, j) or first_match and match(i, j + 1)
            return first_match and match(i + 1, j + 1)

        return match(0, 0)
