class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:

        # Find the path's maximum elevation that is the minimum from (0, 0) to (n-1, n-1)
        n = len(grid)
        pq = [[grid[0][0], 0, 0]]
        vis = set()
        vis.add((0, 0))

        dz = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        def isValid(x, y):
            if x < 0 or x >= n or y < 0 or y >= n:
                return False
            return True

        while pq:
            cur_max, x, y = heappop(pq)

            if x == n - 1 and y == n - 1:
                return cur_max

            for dx, dy in dz:
                newx, newy = dx + x, dy + y
                if isValid(newx, newy) and (newx, newy) not in vis:
                    heappush(pq, [max(cur_max, grid[newx][newy]), newx, newy])
                    vis.add((newx, newy))

        return max(max(grid))
