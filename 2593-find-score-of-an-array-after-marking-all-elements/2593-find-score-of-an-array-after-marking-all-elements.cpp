class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<bool>vis(n);
        map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            adj[nums[i]].push_back(i);
        }
        long long ans=0;
        for(auto [a,indexes]:adj){
            for(auto idx:indexes){
                if(vis[idx])continue;
                ans+=nums[idx];
                vis[idx]=1;
                if(idx)vis[idx-1]=1;
                if(idx+1<n)vis[idx+1]=1;
            }
        }
        return ans;
    }
};