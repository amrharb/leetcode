class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        ans = 10**9
        mp = defaultdict(int)
        n = len(nums)
        for i in range(n):
            s = str(nums[i])
            if s in mp:
                ans = min(ans, i - mp[s])
            while s[-1] == "0":
                s = s[:-1]
            s = s[::-1]
            mp[s] = i
        if ans == 10**9:
            return -1
        return ans
