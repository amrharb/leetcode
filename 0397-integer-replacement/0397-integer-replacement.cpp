class Solution {
public:
    #define ll long long
    int integerReplacement(ll n) {
        int cnt=0;
        while(n!=1){
            if(!(n&1))n/=2;
            else{
                if(!(n&1)||n==3)n--;
                else if(!((n/2+1)&1))n++;
                else n--;
            }
            cnt++;
        }
        return cnt;
    }
};