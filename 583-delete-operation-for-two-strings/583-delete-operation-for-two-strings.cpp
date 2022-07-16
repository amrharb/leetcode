class Solution {
public:
    int minDistance(string s,string x) {
        int n=s.size(),m=x.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(!i||!j)dp[i][j]=i+j;
                else if(s[i-1]==x[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};