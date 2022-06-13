class Solution {
public:
    int n,m,dp[1005][1005];
    string s,x;
    int solve(int i,int j){
        if(i==n||j==m)return 0;
        int &ret=dp[i][j];
        if(~ret)return ret;
        if(s[i]==x[j])return ret=1+solve(i+1,j+1);
        return ret=max(solve(i+1,j),solve(i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size(),m=text2.size(),s=text1,x=text2;
        memset(dp,-1,sizeof dp);
        return solve(0,0);
    }
};