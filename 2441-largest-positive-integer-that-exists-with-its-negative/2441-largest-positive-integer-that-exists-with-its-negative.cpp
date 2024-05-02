class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(auto&it:nums)
        {
            if(it>0)break;
            if(lower_bound(nums.begin(),nums.end(),-it)!=nums.end()&&*lower_bound(nums.begin(),nums.end(),-it)==-it)
                return -it;
        }
        return -1;
    }
};