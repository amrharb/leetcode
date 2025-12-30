class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        ans = 0
        for i in range(n - 2):
            for j in range(m - 2):
                diagonal = defaultdict(int)
                revDiagonal = defaultdict(int)
                row = defaultdict(int)
                col = defaultdict(int)
                nums = set()
                for k in range(3):
                    for l in range(3):
                        x, y = i + k, j + l
                        nums.add(grid[x][y])
                        diagonal[x - y] += grid[x][y]
                        revDiagonal[x + y] += grid[x][y]
                        row[x] += grid[x][y]
                        col[y] += grid[x][y]
                if len(nums) == 9 and min(nums) == 1 and max(nums) == 9:
                    ans += (
                        max(row.values()) == min(row.values())
                        and max(col.values()) == min(col.values())
                        and diagonal[i - j] == revDiagonal[i + j + 2]
                    )
        return ans
