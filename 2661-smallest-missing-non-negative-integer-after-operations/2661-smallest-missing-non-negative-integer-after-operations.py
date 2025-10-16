class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        freq = defaultdict(int)
        for num in nums:
            num = (num % value + value) % value
            freq[num] += 1
        n = len(nums)
        for x in range(0, n):
            if freq[x % value] < (x + value) // value:
                return x
        return n
