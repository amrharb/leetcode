class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=i+1;
        }
        for(int i=0;i<n;i++){
            int k=target-nums[i];
            if(mp[k]!=i+1&&mp[k])return {i,mp[k]-1};
        }
        return {n,n};
    }
};