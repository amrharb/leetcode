class Solution {
public:
    int n;
    string s;
    int dp[105];
    int solve(int i){
        if(i==n)return 1;
        int &ret=dp[i];
        if(~ret)return ret;
        if(s[i]=='0')return ret=0;
        ret=solve(i+1);
        if(i!=n-1&&stoi(s.substr(i,2))<=26)ret+=solve(i+2);
        return ret;
    }
    int numDecodings(string x) {
        memset(dp,-1,sizeof dp);
        s=x;
        n=s.size();
        return solve(0);
    }
};