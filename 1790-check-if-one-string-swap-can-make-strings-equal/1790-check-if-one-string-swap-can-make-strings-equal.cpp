class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size(),m=s2.size(),cnt=0,mx=0;
        if(n!=m)return 0;
        else if(s1==s2)return 1;
        map<char,int>mp;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i])cnt++;
            mp[s1[i]]++;
            mx=max(mx,mp[s1[i]]);
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1==s2&&(cnt==2||cnt==0&&mx>1))return 1;
        return 0;
    }
};