class Solution
{
public:
    int maxProduct(vector<int>& v)
    {
        int n=v.size(),mx=1,mn=1,ans=INT_MIN;
        for(int i=0;i<n;i++){
            int tempMx=mx,tempMn=mn;
            mx=max({v[i]*tempMx,v[i]*tempMn,v[i]});
            mn=min({v[i]*tempMx,v[i]*tempMn,v[i]});
            ans=max(ans,mx);
        }
        return ans;
    }
};