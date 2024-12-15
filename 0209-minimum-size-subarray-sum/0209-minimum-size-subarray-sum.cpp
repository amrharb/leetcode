class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,n=nums.size(),sum=0,mnLen=n+1;
        while(l<n){
            while(r<n&&sum<target){
                sum+=nums[r];
                r++;
            }
            if(sum>=target)
                mnLen=min(mnLen,r-l);
            sum-=nums[l];
            l++;
        }
        return (mnLen==n+1 ? 0:mnLen);
    }
};