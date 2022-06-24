class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a=0;
        while(a*a<=c){
            long long sq=sqrt(c-a*a);
            if(sq*sq==c-a*a)return 1;
            else a++;
        }
        return 0;
    }
};