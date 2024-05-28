class Solution {
public:
    bool add(vector<int>&pref,int x)
    {
        for(int i=0;i<30;i++)
        {
            if(pref[i]&&(x&(1<<i)))
                return false;
        }
        for(int i=0;i<30;i++)
        {
            pref[i]+=((x>>i)&1);
        }
        return true;
    }
    void remove(vector<int>&pref,int x)
    {
        for(int i=0;i<30;i++)
            pref[i]-=((x>>i)&1);
    }
    int longestNiceSubarray(vector<int>& nums) {
        vector<int>pref(30);
        int mx=0,l=0,r=0,n=nums.size();
        while(l<n)
        {
            while(r<n&&add(pref,nums[r]))
                r++;
            mx=max(mx,r-l);
            remove(pref,nums[l++]);
        }
        return mx;
    }
};