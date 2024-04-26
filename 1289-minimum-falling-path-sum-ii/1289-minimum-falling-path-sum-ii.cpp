class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        for(int j=0;j<m;j++)
            dp[0][j]=v[0][j];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    if(j!=k)
                        dp[i][j]=min(dp[i][j],v[i][j]+dp[i-1][k]);
                }
            }
        }
        int mn=1e9;
        for(int j=0;j<m;j++)
            mn=min(mn,dp[n-1][j]);
        return mn;
    }
};