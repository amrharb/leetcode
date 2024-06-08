class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<long long,int>mp;
        bool f=0;
        long long sum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            (sum+=nums[i])%=k;
            if(mp.count(sum)){
                if(i-mp[sum]>1)f=1;}
            else
                mp[sum]=i;
        }
        return f;
    }
};