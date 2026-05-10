class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        return (~n) & ((1 << int(ceil(log2(n)))) - 1);
    }
};