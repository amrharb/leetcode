class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<35>s(n);
        return s.count();
    }
};