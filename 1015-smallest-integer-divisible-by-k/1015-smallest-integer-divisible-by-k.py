class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        curr = 0
        for i in range(10**6):
            curr = (curr * 10 + 1) % k
            if curr % k == 0:
                return i + 1
        return -1
