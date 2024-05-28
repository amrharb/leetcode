class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int mx=0,n=s.size();
        vector<int>cost(n+1);
        for(int i=1;i<=n;i++)
            cost[i]=abs(s[i-1]-t[i-1]);
        int l=1,r=1,total=0;
        while(l<=n)
        {
            while(r<=n&&total+cost[r]<=maxCost)
            {
                total+=cost[r++];
            }
            mx=max(mx,r-l);
            total-=cost[l++];
        }
        return mx;
    }
};