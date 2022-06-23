class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>mp;
        int i=1;
        for(auto it:order)mp[it]=i++;
        string last="0";
        for(auto it:words){
            for(i=0;i<min(last.size(),it.size());i++){
                if(mp[last[i]]<mp[it[i]])break;
                else if(mp[last[i]]>mp[it[i]])return 0;
            }
            if(i==min(last.size(),it.size())&&last.size()>it.size())return 0;
            last=it;
        }
        return 1;
    }
};