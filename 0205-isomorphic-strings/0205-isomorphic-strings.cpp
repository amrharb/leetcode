class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size(),m=t.size();
        map<char,char>mp,mk;
        if(n!=m)return 0;
        for(int i=0;i<n;i++){
            if(mp.find(t[i])==mp.end()&&mk.find(s[i])==mk.end())mp[t[i]]=s[i],mk[s[i]]=t[i];
            else if(mp[t[i]]!=s[i]||mk[s[i]]!=t[i])return 0;
        }
        return 1;
    }
};