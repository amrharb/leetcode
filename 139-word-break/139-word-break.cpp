class Solution {
public:
    bool wordBreak(string s,vector<string>& word) {
        int n=s.size();
        vector<bool>dp(n+1);
        map<string,bool>mp;
        for(auto it:word)mp[it]=1;
        dp[0]=1;
        for(int i=0;i<n;i++){
            if(!dp[i])continue;
            string x;
            for(int j=i;j<n;j++){
                x+=s[j];
                if(mp.find(x)!=mp.end())dp[j+1]=1;
            }
        }
        return dp[n];
    }
};