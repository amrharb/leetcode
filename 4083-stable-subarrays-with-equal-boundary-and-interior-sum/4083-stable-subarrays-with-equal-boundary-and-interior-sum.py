class Solution:
    def countStableSubarrays(self, nums: List[int]) -> int:
        freq = defaultdict(list)
        n = len(nums)
        pref = 0
        for i in range(n):
            pref += nums[i]
            freq[nums[i]].append((i, pref))
        ans = 0
        for key, lst in freq.items():
            mp = defaultdict(int)
            last = None
            for idx, pref in lst:
                target = pref - 2 * key
                ans += mp[target] - ((idx - 1, target) == last)
                mp[pref] += 1
                last = (idx, target)
        return ans
