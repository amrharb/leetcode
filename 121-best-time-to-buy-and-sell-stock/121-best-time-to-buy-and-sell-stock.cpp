class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size(),dp[n],mx=0;
        dp[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            mx=max(mx,dp[i+1]-v[i]);
            dp[i]=max(v[i],dp[i+1]);
        }
        return mx;
    }
};