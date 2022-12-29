class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int MAX=1e4+1;
        vector<int>freq(MAX),ans(MAX);
        int n=nums.size();
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        for(int i=1;i<MAX;i++){
            ans[i]=max(ans[i-1],freq[i]*i+(i>1 ? ans[i-2]:0));
        }
        return ans[MAX-1];
    }
};