class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort()
        print(events)

        @lru_cache(None)
        def solve(i, taken):
            if taken == 2 or i == len(events):
                return 0
            next_idx = bisect_right(events, [events[i][1], 10**9, 10**9])
            ret = max(solve(i + 1, taken), events[i][2] + solve(next_idx, taken + 1))
            return ret

        return solve(0, 0)
