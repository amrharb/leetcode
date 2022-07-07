class Solution {
public:
    int n,m,k;
    string s,x,y;
    int dp[205][205];
    bool solve(int i,int j){
        if(i==n&&j==m)return 1;
        int &ret=dp[i][j];
        if(~ret)return ret;
        ret=0;
        if(i<n&&s[i]==y[i+j])ret|=solve(i+1,j);
        if(j<m&&x[j]==y[i+j])ret|=solve(i,j+1);
        return ret;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size(),m=s2.size(),k=s3.size(),s=s1,x=s2,y=s3;
        memset(dp,-1,sizeof dp);
        return n+m==k&&solve(0,0);
    }
};