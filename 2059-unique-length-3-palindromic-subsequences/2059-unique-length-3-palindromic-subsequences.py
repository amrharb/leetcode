class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        suff = defaultdict(int)
        for ch in s:
            suff[ch] += 1
        all = ""
        for i in range(26):
            all += chr(i + ord("a"))
        print(all)
        pref = defaultdict(int)
        ans = set()
        for ch in s:
            suff[ch] -= 1
            for c in all:
                if pref[c] and suff[c]:
                    ans.add(c + ch + c)
            pref[ch] += 1
        return len(ans)
