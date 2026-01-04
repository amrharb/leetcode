class Solution:
    def __init__(self):
        n = 10**5 + 1
        self.prime = [True] * n
        self.spf = [i for i in range(n)]
        self.prime[0] = self.prime[1] = False
        for i in range(2, n):
            if not self.prime[i]:
                continue
            for j in range(i * i, n, i):
                if self.spf[j] == j:
                    self.spf[j] = i
                self.prime[j] = False

    def sumFourDivisors(self, nums: List[int]) -> int:
        summ = 0
        for num in nums:
            spf = self.spf[num]
            other = num // spf
            if spf != num and (
                self.prime[other] and spf != other or other == spf * spf
            ):
                summ += 1 + spf + other + num
        return summ
