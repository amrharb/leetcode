class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=0;
        for(auto&it:nums)mx=max(mx,it);
        int cnt=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mx)cnt++;
            else cnt=0;
            ans=max(ans,cnt);
        }
        return ans;
    }
};