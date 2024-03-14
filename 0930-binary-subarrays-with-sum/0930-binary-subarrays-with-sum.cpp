class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mp;
        mp[0]=1;
        int sum=0,ans=0;
        for(auto&it:nums)
        {
            sum+=it;
            ans+=mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};