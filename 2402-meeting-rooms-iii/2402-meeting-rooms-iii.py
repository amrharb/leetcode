class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        rooms = []
        freq = [0] * n
        for i in range(n):
            heapq.heappush(rooms, i)
        meetings.sort()
        meets = []
        for start, end in meetings:
            while meets and meets[0][0] <= start:
                top = heapq.heappop(meets)
                heapq.heappush(rooms, top[1])

            if not rooms:
                top = heapq.heappop(meets)
                heapq.heappush(rooms, top[1])
                end += top[0] - start

            min_room = heapq.heappop(rooms)
            heapq.heappush(meets, (end, min_room))
            freq[min_room] += 1

        maxFreqRoom = 0
        for i in range(n):
            if freq[i] > freq[maxFreqRoom]:
                maxFreqRoom = i

        return maxFreqRoom
