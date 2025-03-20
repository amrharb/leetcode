class Solution {
public:
    bool checkPowersOfThree(int n) {
        int cur=1;
        for(int i=1;i<=n;i*=3){
            cur=i;
        }
        while(n&&cur){
            if(n>=cur)n-=cur;
            cur/=3;
        }
        return !n;
    }
};