class Solution {
public:
    unordered_map<char,int> ft,cur;
    bool check()
    {
        for(auto&[a,b]:ft)
            if(b>cur[a])
                return 0;
        return 1;
    }
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        for(int i=0;i<m;i++)
            ft[t[i]]++;
        int i=0,j=0,mn=1e9,l=0,r=-1;
        while(i<n)
        {
            while(j<n&&!check())
            {
                cur[s[j++]]++;
            }
            if(check()&&j-i<mn)
                mn=j-i,l=i,r=j-1;
            cur[s[i++]]--;
        }
        return s.substr(l,r-l+1);
    }
};