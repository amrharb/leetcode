class Solution {
public:
    bool isHappy(long long n) {
        int i=10000;
        while(i--){
            long long x=0;
            while(n){
                x+=(n%10)*(n%10);
                n/=10;
            }
            n=x;
            if(n==1)return 1;
        }
        return 0;
    }
};