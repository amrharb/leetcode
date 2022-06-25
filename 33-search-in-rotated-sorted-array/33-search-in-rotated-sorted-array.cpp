class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]=i+1;
        return mp[target]-1;
    }
};