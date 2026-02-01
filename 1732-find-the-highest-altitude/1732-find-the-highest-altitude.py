class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        maxPref = 0
        pref = 0
        for g in gain:
            pref += g
            maxPref = max(pref, maxPref);
        return maxPref