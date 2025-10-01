class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        l = r = cnt = ans = 0
        freq = defaultdict(int)
        n = len(nums)
        while l < n:
            while r < n and cnt < k:
                cnt += freq[nums[r]]
                freq[nums[r]] += 1
                r += 1
            if cnt >= k:
                ans += n - r + 1
            freq[nums[l]] -= 1
            cnt -= freq[nums[l]]
            l += 1
        return ans
