class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        pref = defaultdict(int)
        suf = defaultdict(int)
        mod = 10 ** 9 + 7
        ans = 0
        for num in nums:
            suf[num] += 1
        for num in nums:
            suf[num] -= 1
            if num * 2 in pref and num * 2 in suf:
                ans += pref[num * 2] * suf[num * 2]
                ans %= mod
            pref[num] += 1
        return ans
