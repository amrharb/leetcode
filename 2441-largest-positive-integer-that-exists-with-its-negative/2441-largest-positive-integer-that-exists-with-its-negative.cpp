class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto&it:nums)
        {
            if(it>0)break;
            auto idx=lower_bound(nums.begin(),nums.end(),-it);
            if(idx!=nums.end()&&*idx==-it)
                return -it;
        }
        return -1;
    }
};