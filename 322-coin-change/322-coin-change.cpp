class Solution {
public:
    long long dp[12][10004];
    vector<int>v;
    long long solve(int i,int rem){
        if(i==v.size()||rem<=0)return abs(rem)*1e6;
        long long &ret=dp[i][rem];
        if(~ret)return ret;
        return ret=min(1+solve(i,rem-v[i]),solve(i+1,rem));
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        v=coins;
        int ans=solve(0,amount);
        if(ans>=1e6)ans=-1;
        return ans;
    }
};