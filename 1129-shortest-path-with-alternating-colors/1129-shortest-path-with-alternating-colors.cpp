class Solution {
public:
    bool vis[105][2];
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        memset(vis,0,sizeof vis);
        vector<vector<vector<int>>>adj(n,vector<vector<int>>(2));
        for(auto&it:red)adj[it[0]][0].push_back(it[1]);
        for(auto&it:blue)adj[it[0]][1].push_back(it[1]);
        vector<int>ans(n,-1);
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            auto cur=q.front().first,color=q.front().second;
            q.pop();
            if(vis[cur][color])continue;
            vis[cur][color]=1;
            if(ans[cur]==-1)ans[cur]=steps;
            for(auto&it:adj[cur][!color]){
                q.push({it,!color});
            }
        }
            steps++;
        }
        return ans;
    }
};