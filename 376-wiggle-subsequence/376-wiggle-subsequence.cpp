class Solution {
public:
    int wiggleMaxLength(vector<int>& v) {
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(2,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i]>v[j])dp[i][0]=max(dp[i][0],1+dp[j][1]);
                else if(v[i]<v[j])dp[i][1]=max(dp[i][1],1+dp[j][0]);
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};