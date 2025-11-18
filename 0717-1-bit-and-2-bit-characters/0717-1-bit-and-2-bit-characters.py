class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        last = 0
        n = len(bits)
        for i in range(n - 1):
            if bits[i] == 1:
                last ^= 1
            else:
                last = 0
        return not last
