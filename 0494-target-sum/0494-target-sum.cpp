class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(),cnt=0;
        vector<int>sum(1<<n);
        for(int i=0;i<n;i++)sum[0]-=nums[i];
        cnt+=(sum[0]==target);
        for(int i=1;i<(1<<n);i++){
            int first_set_bit=log2(i&~(i-1));
            sum[i]=sum[i^(1<<first_set_bit)]+2*nums[first_set_bit];
            cnt+=(sum[i]==target);
        }
        return cnt;
    }
};