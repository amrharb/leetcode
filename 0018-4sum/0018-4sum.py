class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        dict = defaultdict(int)
        n = len(nums)
        for i in range(n):
            dict[nums[i]] = i
        ans = set()
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    need = target - (nums[i] + nums[j] + nums[k])
                    if need in dict and dict[need] not in (i, j, k):
                        cur = [nums[i], nums[j], nums[k], need]
                        cur.sort()
                        ans.add(tuple(cur))
        return list(ans)
