class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        mp = defaultdict(bool)
        ans = []
        for num in nums:
            if num in mp:
                ans.append(num)
            mp[num] = True
        return ans
