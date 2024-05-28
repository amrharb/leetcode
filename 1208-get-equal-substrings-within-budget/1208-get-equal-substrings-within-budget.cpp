class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int mx=0,n=s.size();
        vector<int>pref(n);
        for(int i=0;i<n;i++)
            pref[i]=(i ? pref[i-1]:0)+abs(s[i]-t[i]);
        for(int i=0;i<n;i++)
        {
            int l=i,r=n-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(pref[mid]-(i ? pref[i-1]:0)<=maxCost)
                    l=mid+1;
                else
                    r=mid-1;
            }
            mx=max(mx,l-i);
        }
        return mx;
    }
};