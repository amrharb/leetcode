class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        summ = sum(apple)
        capacity.sort(reverse=True)
        for i in range(1, len(capacity)):
            capacity[i] += capacity[i - 1]
        return bisect_left(capacity, summ) + 1
