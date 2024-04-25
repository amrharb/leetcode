const int N=1e5+5,M=100;
class Solution {
public:
    int dp[N][M],n,k;
    string s;
    int solve(int i,int last)
    {
        if(i==n)
            return 0;
        int &ret=dp[i][last];
        if(~ret)
            return ret;
        ret=solve(i+1,last);
        if(last==26||abs(s[i]-'a'-last)<=k)
            ret=max(ret,1+solve(i+1,s[i]-'a'));
        return ret;
    }
    int longestIdealString(string x, int K) {
        memset(dp,-1,sizeof dp);
        k=K;
        s=x;
        n=s.size();
        return solve(0,26);
    }
};