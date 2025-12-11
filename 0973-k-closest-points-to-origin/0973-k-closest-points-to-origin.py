class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for x, y in points:
            heapq.heappush(heap, (x * x + y * y, x, y))
        ans = []
        for i in range(k):
            top = heapq.heappop(heap)
            ans.append([top[1], top[2]])
        return ans
