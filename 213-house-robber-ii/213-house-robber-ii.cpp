class Solution {
public:
    int rob(vector<int>& v) {
        int n=v.size();
        if(n==1)return v.back();
        if(n==2)return max(v.back(),v.front());
        vector<vector<int>>dp(n+15,vector<int>(15,0));
        dp[0][1]=v[0],dp[0][0]=0;
        dp[1][0]=dp[0][0]+v[1];
         dp[1][1]=dp[0][1];
        for(int i=2;i<n-1;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-2][0]+v[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-2][1]+v[i]);
        }
        int i=n-1;
        dp[i][0]=max(dp[i-1][0],dp[i-2][0]+v[i]);
        dp[i][1]=dp[i-1][1];
        return max(dp[n-1][1],dp[n-1][0]);
    }
};