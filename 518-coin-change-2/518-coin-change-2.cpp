class Solution {
public:
    int dp[305][5005];
    vector<int>v;
    long long solve(int i,int rem){
        if(i==v.size()||rem<=0)return !rem;
        int &ret=dp[i][rem];
        if(~ret)return ret;
        return ret=solve(i,rem-v[i])+solve(i+1,rem);
    }
    int change(int amount, vector<int>& coins) {
         memset(dp,-1,sizeof dp);
        v=coins;
        return solve(0,amount);
    }
};