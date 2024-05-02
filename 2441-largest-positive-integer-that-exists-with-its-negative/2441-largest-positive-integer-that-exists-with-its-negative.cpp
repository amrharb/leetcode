class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int idx,n=nums.size();
        for(auto&it:nums)
        {
            if(it>0)break;
            idx=lower_bound(nums.begin(),nums.end(),-it)-nums.begin();
            if(idx<nums.size()&&nums[idx]==-it)
                return -it;
        }
        return -1;
    }
};