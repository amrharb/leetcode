class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0,n=nums.size();
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            (sum+=nums[i])%=k;
            if(mp.count(sum)){
                if(i-mp[sum]>1)return 1;}
            else
                mp[sum]=i;
        }
        return 0;
    }
};