class Solution {
public:
    int vis[1005],ans=-1;
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj(n);
        for(auto&it:trust)vis[it[1]-1]++,adj[--it[0]].push_back(--it[1]);
        for(int i=0;i<n;i++){
            if(vis[i]==n-1&&!adj[i].size())ans=i+1;
        }
        return ans;
    }
};