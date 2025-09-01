class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        items = []
        n = len(names)
        for i in range(n):
            items.append([heights[i], names[i]])
        items.sort(reverse=True)
        ans = []
        for i in range(n):
            ans.append(items[i][1])
        return ans