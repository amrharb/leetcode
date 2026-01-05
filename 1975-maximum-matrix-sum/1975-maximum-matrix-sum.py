class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        mn = 10**5
        summ = 0
        isNegOdd = False
        for row in matrix:
            for num in row:
                summ += abs(num)
                mn = min(mn, abs(num))
                if num < 0:
                    isNegOdd = 1 - isNegOdd
        if isNegOdd:
            summ -= 2 * mn
        return summ
