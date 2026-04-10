class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        ans = 10**18
        n = len(nums)
        adj = defaultdict(list)
        for i in range(n):
            adj[nums[i]].append(i)
        for num in adj:
            if len(adj[num]) > 2:
                for j in range(2, len(adj[num])):
                    ans = min(
                        ans,
                        adj[num][j - 1]
                        - adj[num][j - 2]
                        + adj[num][j]
                        - adj[num][j - 1]
                        + adj[num][j]
                        - adj[num][j - 2],
                    )
        if ans == 10**18:
            return -1
        return ans
