class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        vector<vector<int>>ans(n,vector<int>(2));
        ans[0][1]=nums[0];
        ans[1][0]=nums[1];
        ans[1][1]=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            ans[i][0]=max(ans[i-1][0],nums[i]+ans[i-2][0]);
            ans[i][1]=max({ans[i-1][0],ans[i-1][1],nums[i]+ans[i-2][1]});
        }
        return max({ans[n-3][0]+nums[n-1],ans[n-2][1],ans[n-2][0]});
    }
};