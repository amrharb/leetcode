class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        freq = {}
        ans = 0
        for word in words:
            rev_word = word[::-1]
            ans += freq.get(rev_word, 0)
            freq[word] = freq.get(word, 0) + 1
        return ans
