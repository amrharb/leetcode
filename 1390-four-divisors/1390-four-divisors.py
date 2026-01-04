class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        summ = 0
        for num in nums:
            cnt = 0
            curr = 0
            sq = int(sqrt(num))
            for i in range(1, sq + 1):
                if num % i == 0:
                    cnt += 1
                    curr += i
                    if i * i != num:
                        cnt += 1
                        curr += num // i
            if cnt == 4:
                summ += curr
        return summ
