class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        summ = 0
        happiness.sort(reverse=True)
        for i in range(k):
            summ += max(0, happiness[i] - i)
        return summ