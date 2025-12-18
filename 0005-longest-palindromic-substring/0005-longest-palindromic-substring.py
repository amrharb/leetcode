class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        dp = [[-1 for _ in range(n)] for _ in range(n)]

        def check(i, j):
            if i > j:
                return True
            if i == j:
                return True
            if s[i] != s[j]:
                return False
            if dp[i][j] != -1:
                return dp[i][j]
            dp[i][j] = check(i + 1, j - 1)
            return dp[i][j]

        ans = start = 0
        for i in range(n):
            for j in range(i, n):
                if j - i + 1 > ans and check(i, j):
                    ans = j - i + 1
                    start = i
        return s[start : start + ans]
