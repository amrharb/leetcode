class Solution {
public:
    int minDeletions(string s) {
        int mx=0,cnt=0;
        map<char,int>mp;
        map<int,int>mk;
        set<int>st;
        for(auto&it:s)mp[it]++;
        for(auto&it:mp)mk[it.second]++,mx=max(mx,it.second);
        for(int i=1;i<=mx;i++)st.insert(i);
        for(auto&it:mp){
            auto k=st.upper_bound(it.second);
            if(k==st.begin())cnt+=it.second;
            else{
                k--;
                cnt+=it.second-*k;
                st.erase(k);
            }
        }
        return cnt;
    }
};