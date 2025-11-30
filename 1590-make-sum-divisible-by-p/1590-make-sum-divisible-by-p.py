class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        sub_sum = sum(nums) % p
        if not sub_sum:
            return 0
        n = len(nums)
        summ = 0
        mp = defaultdict(int)
        mp[summ] = -1
        ans = n
        for i, num in enumerate(nums):
            summ += num
            summ %= p
            target = ((summ - sub_sum) % p + p) % p
            if target in mp:
                ans = min(ans, i - mp[target])
            mp[summ] = i
        return ans if ans < n else -1
