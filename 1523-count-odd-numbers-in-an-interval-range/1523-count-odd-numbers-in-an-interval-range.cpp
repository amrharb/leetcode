class Solution {
public:
    int countOddsUpTo(int n) { return (n + 1) / 2; }
    int countOdds(int low, int high) {
        return countOddsUpTo(high) - countOddsUpTo(low - 1);
    }
};