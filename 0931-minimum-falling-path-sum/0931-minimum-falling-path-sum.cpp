class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>dp;
        dp=v;
        for(int i=1;i<n;i++){
            for(int j=0;j<n ;j++){
                dp[i][j]=dp[i-1][j];
                if(j-1>=0)dp[i][j]=min(dp[i-1][j-1],dp[i][j]);
                if(j+1<n)dp[i][j]=min(dp[i-1][j+1],dp[i][j]);
                dp[i][j]+=v[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};