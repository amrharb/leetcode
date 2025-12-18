class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)

        dp = [[False for _ in range(n)] for _ in range(n)]
        ans = 1
        start = 0
        for i in range(n):
            dp[i][i] = True
        for i in range(n - 1):
            dp[i][i + 1] = s[i] == s[i + 1]
            if dp[i][i + 1]:
                ans = 2
                start = i
        for size in range(3, n + 1):
            for i in range(n - size + 1):
                j = i + size - 1
                dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]
                if dp[i][j] and j - i + 1 > ans:
                    ans = j - i + 1
                    start = i
        return s[start : start + ans]
