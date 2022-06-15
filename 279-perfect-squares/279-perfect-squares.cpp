class Solution {
public:
    int numSquares(int n) {
        vector<int>sq(100),dp(n+1,1e9);
        for(int i=1;i<=100;i++){
            sq[i-1]=i*i;
        }
        dp[0]=0;
        for(int i=0;i<100;i++){
            for(int j=sq[i];j<=n;j++){
                dp[j]=min(dp[j],1+dp[j-sq[i]]);
            }
        }
        return dp[n];
    }
};