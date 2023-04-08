class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bitset<10001>bs;
        int n=nums.size(),xr=n;
        for(int i=0;i<n;i++)
            xr^=i^nums[i];
        return xr;
    }
};