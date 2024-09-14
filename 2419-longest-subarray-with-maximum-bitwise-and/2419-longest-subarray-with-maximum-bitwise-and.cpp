class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        map<int,int>mp;
        for(auto&it:nums)mp[it]++;
        int ans=(*mp.rbegin()).first,cnt=0,mx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ans)cnt++;
            else cnt=0;
            mx=max(mx,cnt);
        }
        return mx;
    }
};