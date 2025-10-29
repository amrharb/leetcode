class Solution:
    def smallestNumber(self, n: int) -> int:
        return (1 << ceil(log2(n + 0.000000000001))) - 1
