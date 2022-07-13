class Solution {
public:
    int dp[1005];
    bool solve(int i){
        int &ret=dp[i];
        if(~ret)return ret;
        ret=0;
        for(int j=1;j<i;j++){
            if(i%j==0){
                return ret=!solve(i-j);
            }
        }
        return ret;
    }
    bool divisorGame(int n) {
        memset(dp,-1,sizeof dp);
        return solve(n);
    }
};