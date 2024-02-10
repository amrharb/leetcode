const int N=1005;
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),cnt=n;
        vector<vector<bool>>dp(n,vector<bool>(n));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            if(i+1<n)
                cnt+=(dp[i][i+1]=(s[i]==s[i+1]));
        }
        for(int i=2;i<n;i++)
        {
            for(int j=0;j+i<n;j++)
            {
                cnt+=(dp[j][i+j]=(s[j]==s[i+j])&&(dp[j+1][i+j-1]));
            }
        }
        return cnt;
    }
};