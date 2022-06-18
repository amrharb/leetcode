class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0),cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt*2==sum-nums[i])return i;
            cnt+=nums[i];
        }
        return -1;
    }
};