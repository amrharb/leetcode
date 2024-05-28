class Solution {
public:
    bool add(vector<int>&pref,int x)
    {
        for(int i=0;i<30;i++)
        {
            if(pref[i]&&(x&(1<<i)))
                return false;
        }
        return true;
    }
    void update(vector<int>&pref,int x,bool f)
    {
        for(int i=0;i<30;i++)
            pref[i]+=(f*2-1)*((x>>i)&1);
    }
    int longestNiceSubarray(vector<int>& nums) {
        vector<int>pref(30);
        int mx=0,l=0,r=0,n=nums.size();
        while(l<n)
        {
            while(r<n&&add(pref,nums[r]))
            {
                update(pref,nums[r++],1);
            }
            mx=max(mx,r-l);
            update(pref,nums[l++],0);
        }
        return mx;
    }
};