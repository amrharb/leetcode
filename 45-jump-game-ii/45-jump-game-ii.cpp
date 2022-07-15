class Solution {
public:
    int jump(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n+1005,1e9);
        dp[0]=0;
        for(int j=1;j<=v[0];j++){
                dp[j]=min(dp[j],1);
            }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<=v[i];j++){
                dp[i+j]=min(dp[i+j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};