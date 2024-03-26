class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,bool>mp;
        for(auto&it:nums)
        {
            if(it>0)
                mp[it]=1;
        }
        int it=1;
        for(auto&[a,b]:mp)
        {
            if(a!=it)
            {
                return it;
            }
            it++;
        }
        return it;
    }
};