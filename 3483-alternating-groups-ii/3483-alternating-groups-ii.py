class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        count = 0
        n = len(colors)
        for i in range(1, k):
            count += colors[i] == colors[i - 1]
        result = count == 0
        for i in range(k, n + k - 1):
            count -= colors[(i - k)] == colors[(i - k + 1)]
            count += colors[i % n] == colors[(i - 1) % n]
            result += count == 0
        return result
