class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        map<int,bool>mp;
        for(auto&it:v)mp[it]=1;
        int mx=0,last=-2e9,cnt=1;
        for(auto&it:mp){
            if(it.first==last+1)cnt++;
            mx=max(mx,cnt);
            if(it.first!=last+1){
               cnt=1;
            }
            last=it.first;
        }
        return mx;
    }
};