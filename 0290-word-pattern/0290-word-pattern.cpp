class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        vector<string>v;
        string x;
        while(iss>>x){
            v.push_back(x);
        }
        int n=pattern.size();
        if(n!=v.size())
            return 0;
        map<string,char>mp;
        map<char,string>mk;
        for(int i=0;i<n;i++){
            if(mp.find(v[i])==mp.end()&&mk.find(pattern[i])==mk.end())
                mp[v[i]]=pattern[i],mk[pattern[i]]=v[i];
            else if((mp.find(v[i])==mp.end())+(mk.find(pattern[i])==mk.end())==1)
                return 0;
            else if(mp[v[i]]!=pattern[i]||mk[pattern[i]]!=v[i])return 0;
        }
        return 1;
    }
};