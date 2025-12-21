class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs)
        m = len(strs[0])
        done = [0] * n
        cnt = 0
        for j in range(m):
            OK = True
            for i in range(1, n):
                if not done[i] and strs[i][j] < strs[i - 1][j]:
                    OK = False
                    cnt += 1
                    break
            if OK:
                for i in range(1, n):
                    if strs[i][j] > strs[i - 1][j]:
                        done[i] = True
        return cnt
