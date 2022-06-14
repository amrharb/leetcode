class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]=min(dp[j],1+dp[j-coins[i]]);
            }
        }
        int ans=dp[amount];
        if(ans>=1e9)ans=-1;
        return ans;
    }
};