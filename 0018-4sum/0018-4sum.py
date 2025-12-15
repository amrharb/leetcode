class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        for i in range(n - 1, 3, -1):
            if nums[i] == nums[i - 4]:
                nums.pop(i)
        n = len(nums)
        dict = defaultdict(list)
        for i in range(n):
            for j in range(i + 1, n):
                dict[nums[i] + nums[j]].append([i, j])
        ans = set()
        for i in range(n):
            for j in range(i + 1, n):
                need = target - (nums[i] + nums[j])
                k, l = j + 1, n - 1
                while k < l:
                    if nums[k] + nums[l] > need:
                        l -= 1
                    elif nums[k] + nums[l] < need:
                        k += 1
                    else:
                        ans.add((nums[i], nums[j], nums[k], nums[l]))
                        l -= 1
                        k += 1
        return list(ans)
