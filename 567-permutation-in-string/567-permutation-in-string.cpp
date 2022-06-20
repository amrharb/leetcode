class Solution {
public:
    bool checkInclusion(string s, string x) {
        int n=s.size(),m=x.size();
        map<char,int>mp,mk;
        for(auto&it:s)mp[it]++;
        int l=0,r=0;
        bool flag=1;
        for(int i=0;i<m;i++){
            if(i>=n)mk[x[i-n]]--;
            mk[x[i]]++;
            flag=1;
            for(char j='a';j<='z';j++){
                if(mp[j]!=mk[j])flag=0;
            }
            if(flag)return 1;
        }
        return 0;
    }
};