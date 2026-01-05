class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        flat = [num for row in matrix for num in row]
        return sum(map(abs, flat)) - 2 * (sum(num < 0 for num in flat) & 1) * min(
            map(abs, flat)
        )
