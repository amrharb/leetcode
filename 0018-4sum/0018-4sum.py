class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        for i in range(n - 1, 3, -1):
            if nums[i] == nums[i - 4]:
                nums.pop(i)
        n = len(nums)
        dict = defaultdict(int)
        for i in range(n):
            dict[nums[i]] = i
        ans = set()
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    need = target - (nums[i] + nums[j] + nums[k])
                    if need in dict and dict[need] > k:
                        ans.add((nums[i],nums[j],nums[k],need))
        return list(ans)
