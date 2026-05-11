class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for num in nums:
            lst = []
            while num:
                lst.append(num%10)
                num //= 10
            lst = lst[::-1]
            ans += lst
        return ans