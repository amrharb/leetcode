class Solution {
public:
    int dp[1005][1005];
    string s;
    int solve(int i,int j){
        if(i>j)return 0;
        if(i==j)return 1;
        int &ret=dp[i][j];
        if(~ret)return ret;
        if(s[i]==s[j])return 2+solve(i+1,j-1);
        return ret=max(solve(i+1,j),solve(i,j-1));
    }
    int longestPalindromeSubseq(string x) {
        s=x;
        memset(dp,-1,sizeof dp);
        return solve(0,s.size()-1);
    }
};