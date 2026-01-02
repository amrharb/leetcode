class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        dict = Counter(nums)
        for k in dict:
            if dict[k] > 1:
                return k
