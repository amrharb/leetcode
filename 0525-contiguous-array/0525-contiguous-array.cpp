class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size(),sum=n,ans=0,shift=n;
        vector<int>mp(2*n+3,-2);
        mp[sum]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i]*2-1;
            if(mp[sum]!=-2)
                ans=max(ans,i-mp[sum]);
            else
                mp[sum]=i;
        }
        return ans;
    }
};