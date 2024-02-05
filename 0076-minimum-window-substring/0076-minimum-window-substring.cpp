class Solution {
public:
    bool check(int s[128],int t[128])
    {
        for(int i=0;i<128;i++)
            if(s[i]<t[i])
                return 0;
        return 1;
    }
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        int ft[128]={},cur[128]={};
        for(int i=0;i<m;i++)
            ft[t[i]]++;
        int i=0,j=0,mn=1e9,l=0,r=-1;
        while(i<n)
        {
            while(j<n&&!check(cur,ft))
            {
                cur[s[j++]]++;
            }
            if(check(cur,ft)&&j-i<mn)
                mn=j-i,l=i,r=j-1;
            cur[s[i++]]--;
        }
        return s.substr(l,r-l+1);
    }
};