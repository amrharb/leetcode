class Solution:
    def isPalindrome(self, x: int) -> bool:
        def reverse(s):
            return s[::-1]

        return str(x) == reverse(str(x))
