const int N=1005;
int dp[N][N];
class Solution {
public:
    
    bool solve(string s,int i,int j)
    {
        if(i>=j)
            return 1;
        int &ret=dp[i][j];
        if(~ret)
            return ret;
        if(s[i]==s[j])
            return ret=solve(s,i+1,j-1);
        return ret=0;
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof dp);
        int n=s.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                cnt+=solve(s,i,j);
            }
        }
        return cnt;
    }
};