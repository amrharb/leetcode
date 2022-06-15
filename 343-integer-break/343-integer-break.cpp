class Solution {
public:
    int dp[59];
    int solve(int rem){
        if(!rem)return !rem;
        int &ret=dp[rem];
        if(~ret)return ret;
        ret=0;
        for(int i=1;i<=rem;i++){
            ret=max(ret,i*solve(rem-i));
        }
        return ret;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof dp);
        int ret=0;
        for(int i=1;i<n;i++)ret=max(ret,i*solve(n-i));
        return ret;
    }
};