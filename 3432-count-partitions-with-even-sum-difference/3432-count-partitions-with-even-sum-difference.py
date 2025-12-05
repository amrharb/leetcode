class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        suf = sum(nums)
        pref = 0
        cnt = 0
        for i in range(len(nums) - 1):
            pref += nums[i]
            suf -= nums[i]
            cnt += not (abs(pref - suf) & 1)
        return cnt
