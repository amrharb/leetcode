class Solution:
    def minOperations(self, nums: List[int]) -> int:
        mp = defaultdict(list)
        nxt = [len(nums)] * len(nums)
        stk = []
        for i,num in enumerate(nums):
            mp[num].append(i)
            while stk and nums[stk[-1]] > num:
                nxt[stk[-1]] = i
                stk.pop()
            stk.append(i)
        ans = 0
        for i, lst in mp.items():
            if not i:
                continue
            ans += 1
            for j in range(len(lst)-1):
                if nxt[lst[j]] < lst[j+1]:
                    ans += 1
        return ans
