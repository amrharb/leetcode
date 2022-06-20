class Solution {
public:
    bool canConstruct(string s, string x) {
        map<char,int>mp;
        for(auto&it:s)mp[it]++;
        for(auto&it:x)mp[it]--;
        for(auto&it:mp)
            if(it.second>0)return 0;
        return 1;
    }
};