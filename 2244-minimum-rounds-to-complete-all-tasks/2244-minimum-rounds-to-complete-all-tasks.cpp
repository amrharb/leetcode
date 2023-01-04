class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        bool flag=0;
        int ans=0;
        for(auto&it:tasks)mp[it]++;
        for(auto&it:mp)flag|=(it.second==1),ans+=(it.second+2)/3;
        if(flag)return -1;
        return ans;
        
    }
};