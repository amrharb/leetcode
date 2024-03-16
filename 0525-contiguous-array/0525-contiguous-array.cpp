class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>mp;
        int sum=0,ans=0,n=nums.size();
        mp[sum]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i]*2-1;
            if(mp.find(sum)!=mp.end())
                ans=max(ans,i-mp[sum]);
            else
                mp[sum]=i;
        }
        return ans;
    }
};