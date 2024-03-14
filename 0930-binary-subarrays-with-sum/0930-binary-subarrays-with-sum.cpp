class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<short>mp(count(nums.begin(),nums.end(),1)+1);
        mp[0]=1;
        short sum=0;
        int ans=0;
        for(auto&it:nums)
        {
            sum+=it;
            if(sum-goal>=0)ans+=mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};