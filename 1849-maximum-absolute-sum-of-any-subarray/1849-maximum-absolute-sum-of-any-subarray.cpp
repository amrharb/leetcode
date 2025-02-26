class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mn_sum=0,mx_sum=0,sum=0,ans=0;
        for(auto num:nums){
            sum+=num;
            mn_sum=min(mn_sum,sum);
            mx_sum=max(mx_sum,sum);
            ans=max(ans,sum-mn_sum);
            ans=max(ans,mx_sum-sum);
        }
        return ans;
    }
};