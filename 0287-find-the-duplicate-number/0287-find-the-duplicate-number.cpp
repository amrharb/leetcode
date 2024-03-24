class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]])return nums[i];
            mp[nums[i]]=1;
        }
        return -1;
    }
};