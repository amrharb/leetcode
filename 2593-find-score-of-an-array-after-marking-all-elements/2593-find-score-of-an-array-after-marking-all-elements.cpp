class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<bool>vis(n);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        long long ans=0;
        for(auto [val,idx]:v){
            if(vis[idx])continue;
            ans+=val;
            vis[idx]=1;
            if(idx)vis[idx-1]=1;
            if(idx+1<n)vis[idx+1]=1;
        }
        return ans;
    }
};