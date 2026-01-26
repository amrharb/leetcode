class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        mn = 10**18
        n = len(arr)
        for i in range(1, n):
            mn = min(mn, arr[i] - arr[i - 1])
        ans = []
        for i in range(1, n):
            if arr[i] - arr[i - 1] == mn:
                ans.append([arr[i - 1], arr[i]])
        return ans
