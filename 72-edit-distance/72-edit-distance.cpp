class Solution {
public:
    int minDistance(string s, string x) {
        int n=s.size(),m=x.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(!i&&!j)dp[i][j]=0;
                else if(!i)dp[i][j]=j;
                else if(!j)dp[i][j]=i;
                else if(s[i-1]==x[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};