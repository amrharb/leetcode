class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        l = r = 0
        mp = defaultdict(int)
        for num in nums:
            mp[num] = 0
        rem = len(mp)
        n = len(nums)
        ans = 0
        while l < n:
            while r < n and rem > 0:
                if mp[nums[r]] == 0:
                    rem -= 1
                mp[nums[r]] += 1
                r += 1
            if not rem:
                ans += n - r + 1
            mp[nums[l]] -= 1
            if mp[nums[l]] == 0:
                rem += 1
            l += 1
        return ans
