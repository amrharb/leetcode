class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size(),ans=n+1;
        #define int long long
        vector<int>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)pref[i]=nums[i]+pref[i-1];
        vector<vector<int>>dp(n,vector<int>(20,-1));
        for(int i=0;i<n;i++)dp[i][0]=pref[i];
        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                if(j+(1<<i-1)>=n)continue;
                dp[j][i]=max(dp[j][i-1],dp[j+(1<<i-1)][i-1]);
            }
        }
        for(int i=0;i<n;i++){
            int l=i,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                int mx=-1e18;
                int dist=mid-i+1,idx=i;
                for(int j=0;j<20;j++){
                    if(dist&(1<<j))
                        mx=max(mx,dp[idx][j]-(i ? pref[i-1]:0)),idx+=(1<<j);
                }
                if(mx>=k)
                    r=mid-1;
                else
                    l=mid+1;
            }
            if(r+1==n)continue;
            int mx=-1e18,dist=r+1-i+1,idx=i;
            for(int j=0;j<20;j++){
                if(dist&(1<<j))
                    mx=max(mx,dp[idx][j]-(i ? pref[i-1]:0)),idx+=(1<<j);
            }
            if(mx>=k)ans=min((int)ans,r-i+2);
        }
        #undef int
        return (ans==n+1 ? -1:ans);
    }
};