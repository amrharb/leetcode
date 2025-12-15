class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        columnTitle = ""
        while columnNumber:
            columnNumber -= 1
            columnTitle += chr(columnNumber % 26 + ord("A"))
            columnNumber //= 26
        return columnTitle[::-1]
