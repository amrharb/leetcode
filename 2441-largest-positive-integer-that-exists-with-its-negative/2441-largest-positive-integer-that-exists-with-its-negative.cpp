class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,bool>mp;
        for(auto&it:nums)
            if(it>0)
                mp[it]=1;
        for(auto&it:nums)
        {
            if(it>0)break;
            if(mp.count(-it))
                return -it;
        }
        return -1;
    }
};