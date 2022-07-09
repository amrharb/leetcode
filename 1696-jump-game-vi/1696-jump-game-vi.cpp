class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,0);
        priority_queue<pair<int,int>>q;
        dp[0]=nums[0];
        q.push({nums[0],0});
        for(int i=1;i<n;i++){
            while(!q.empty()&&q.top().second<i-k)q.pop();
            dp[i]=q.top().first+nums[i];
            q.push({dp[i],i});
        }
        return  dp[n-1];
    }
};