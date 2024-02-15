class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        for(int i=n-1;i>=2;i--)
        {
            if(sum-nums[i]>nums[i])
                return sum;
            sum-=nums[i];
        }
        return -1;
    }
};