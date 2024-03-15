class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size(),prod=1,zeros=0;
        vector<int>pref(n,1),suf(n,1),ans(n,1);
        for(int i=0;i<n;i++)
        {
            if(i)
                pref[i]=pref[i-1];
            pref[i]*=nums[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i!=n-1)
                suf[i]=suf[i+1];
            suf[i]*=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(i)
                ans[i]=pref[i-1];
            if(i+1<n)
                ans[i]*=suf[i+1];
        }
        return ans;
    }
};
