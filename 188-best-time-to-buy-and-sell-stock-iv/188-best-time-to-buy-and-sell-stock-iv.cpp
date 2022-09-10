class Solution {
public:
    int dp[1005][105],n;
    vector<int>price;
    int solve(int i,int rem){
        if(i==n||!rem)return 0;
        int &ret=dp[i][rem];
        if(~ret)return ret;
        ret=solve(i+1,rem);
        for(int j=i+1;j<n;j++)ret=max(ret,price[j]-price[i]+solve(j+1,rem-1));
        return ret;
    }
    int maxProfit(int k, vector<int>& prices) {
       memset(dp,-1,sizeof dp);
        price=prices;
        n=price.size();
        return solve(0,k);
    }
};