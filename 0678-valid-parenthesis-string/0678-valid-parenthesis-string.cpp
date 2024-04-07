int dp[105][205];
class Solution {
public:
    int solve(string &s,int i,int cnt)
    {
        if(i==s.size()||cnt<100)
            return cnt==100;
        int &ret=dp[i][cnt];
        if(~ret)
            return ret;
        ret=0;
        if(s[i]=='*')
            ret=max({solve(s,i+1,cnt+1),solve(s,i+1,cnt-1),solve(s,i+1,cnt)});
        else
            ret=solve(s,i+1,cnt+(s[i]=='(')*2-1);
        return ret;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof dp);
        return solve(s,0,100);
    }
};