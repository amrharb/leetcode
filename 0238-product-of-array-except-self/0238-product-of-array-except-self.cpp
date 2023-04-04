class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size(),prod=1,zeros=0;
        for(int i=0; i<n; i++)
        {
            if(nums[i])
                prod*=nums[i];
            else zeros++;
        }
        for(int i=0; i<n; i++)
        {
            if(nums[i]){
                if(zeros)
                    nums[i]=0;
                else nums[i]=prod/nums[i];
            }
            else{
                if(zeros>1)
                    nums[i]=0;
                else nums[i]=prod;
            }
        }
        return nums;
    }
};
