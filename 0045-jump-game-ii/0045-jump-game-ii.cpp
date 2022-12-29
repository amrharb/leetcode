class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1e9);
        ans[0]=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<min(n,i+nums[i]+1);j++){
                ans[j]=min(ans[j],ans[i]+1);
            }
        }
        return ans[n-1];
    }
};