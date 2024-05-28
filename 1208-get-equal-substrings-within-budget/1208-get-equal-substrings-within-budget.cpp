class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int mx=0,n=s.size();
        vector<int>pref(n+1);
        for(int i=1;i<=n;i++)
            pref[i]=pref[i-1]+abs(s[i-1]-t[i-1]);
        for(int i=1;i<=n;i++)
        {
            int l=i,r=n;
            while(l<=r)
            {
                int mid=l+r>>1;
                if(pref[mid]-pref[i-1]<=maxCost)
                    l=mid+1;
                else
                    r=mid-1;
            }
            mx=max(mx,l-i);
        }
        return mx;
    }
};