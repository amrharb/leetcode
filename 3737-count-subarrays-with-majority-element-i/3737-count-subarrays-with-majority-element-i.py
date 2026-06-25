class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            freq = defaultdict(int)
            for j in range(i, n):
                freq[nums[j]] += 1
                if freq[target] > (j - i + 1) // 2:
                    ans += 1
        return ans
