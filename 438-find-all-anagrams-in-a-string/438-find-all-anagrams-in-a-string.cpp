class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),m=p.size();
        vector<int>ans;
        map<char,int>mp,mk;
        for(auto&it:p)mk[it]++;
        int l=0,r=0;
        while(l<n){
            while(r<n&&r-l+1<=m&&mp[s[r]]<mk[s[r]]){
                mp[s[r++]]++;
            }
            bool flag=1;
            for(auto&it:mk){
                if(it.second!=mp[it.first]){
                    flag=0;
                    break;
                }
            }
            if(flag)ans.push_back(l);
            mp[s[l++]]--;
        }
        return ans;
    }
};