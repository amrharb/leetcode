class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i&&!j)dp[i][j]=1;
                else if(!i)dp[i][j]=dp[i][j-1];
                else if(!j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};