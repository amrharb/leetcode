class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        ans = 1
        last = defaultdict(int)
        last["a"] = last["b"] = last["c"] = n
        for i in range(n - 1, -1, -1):
            mn = n
            for ch, f in last.items():
                if ch != s[i]:
                    mn = min(mn, f - i)
            ans = max(ans, mn)
            last[s[i]] = i

        def calc(a, b):
            pref = 0
            idx = {0: -1}
            mx = 0
            for i, ch in enumerate(s):
                if ch not in (a, b):
                    pref = 0
                    idx = {0: i}
                else:
                    pref += 1 if ch == a else -1
                    if pref in idx:
                        mx = max(mx, i - idx[pref])
                    else:
                        idx[pref] = i
            return mx

        ans = max(ans, calc("a", "b"), calc("b", "c"), calc("a", "c"))
        pref = [[0 for _ in range(3)] for _ in range(n)]
        index = {0: -1}
        sm = 0
        score = [1, 10**6, -(10**6) - 1]
        for i in range(n):
            if i > 0:
                for j in range(3):
                    pref[i][j] = pref[i - 1][j]
            idx = ord(s[i]) - ord("a")
            pref[i][idx] += 1
            sm += score[idx]
            if sm in index:
                ans = max(ans, i - index[sm])
            else:
                index[sm] = i
        return ans
