class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return 0;
        bitset<32>s(n);//here we store the binary representation of n in s
        // the number of ones in binary representation is one
        return s.count()==1;
    }
};