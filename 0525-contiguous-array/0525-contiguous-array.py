class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        prefIndex = defaultdict(int)
        prefIndex[0] = -1
        pref = ans = 0
        for i in range(len(nums)):
            pref += nums[i] * 2 - 1
            if pref in prefIndex:
                ans = max(ans, i - prefIndex.get(pref, i))
            else:
                prefIndex[pref] = i
        return ans
