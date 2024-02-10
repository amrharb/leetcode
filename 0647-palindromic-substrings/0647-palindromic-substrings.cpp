class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),cnt=0;
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            cnt+=dp[i][i];
            if(i+1<n)
                dp[i][i+1]=(s[i]==s[i+1]),cnt+=dp[i][i+1];
        }
        for(int i=2;i<n;i++)
        {
            for(int j=0;j+i<n;j++) 
            {
                dp[j][i+j]=(s[j]==s[i+j])&&(dp[j+1][i+j-1]);
                cnt+=dp[j][i+j];
            }
        }
        return cnt;
    }
};