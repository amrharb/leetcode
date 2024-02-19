class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return 0;
        int cnt=0;
        while(n){
            cnt+=n%2;
            n/=2;
        }
        return cnt==1;
    }
};