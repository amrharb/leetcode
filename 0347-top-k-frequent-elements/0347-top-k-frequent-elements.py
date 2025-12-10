class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        for num in nums:
            freq[num] += 1
        heap = []
        for key, f in freq.items():
            heapq.heappush(heap, (-f, key))
        ans = []
        for i in range(k):
            item = heapq.heappop(heap)
            ans.append(item[1])
            if not heap:
                break
        return ans
