class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        mn = min(abs(num) for row in matrix for num in row)
        summ = sum(abs(num) for row in matrix for num in row)
        isNegOdd = sum(1 for row in matrix for num in row if num < 0) & 1
        return summ - isNegOdd * 2 * mn
