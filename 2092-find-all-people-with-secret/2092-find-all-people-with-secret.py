class Solution:
    def findAllPeople(
        self, n: int, meetings: List[List[int]], firstPerson: int
    ) -> List[int]:
        adj = [[] for _ in range(n)]
        for person1, person2, t in meetings:
            adj[person1].append((person2, t))
            adj[person2].append((person1, t))
        INF = 10**9
        time = [INF] * n
        minHeap = []
        heapq.heappush(minHeap, (0, 0))
        heapq.heappush(minHeap, (0, firstPerson))
        time[0] = time[firstPerson] = 0
        while minHeap:
            curTime, curPerson = heapq.heappop(minHeap)
            if time[curPerson] < curTime:
                continue
            for nxtPerson, nxtTime in adj[curPerson]:
                if nxtTime < curTime:
                    continue
                if time[nxtPerson] > nxtTime:
                    time[nxtPerson] = nxtTime
                    heapq.heappush(minHeap, (nxtTime, nxtPerson))
        ans = []
        for person in range(n):
            if time[person] != INF:
                ans.append(person)
        return ans
