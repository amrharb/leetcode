class Solution {
public:
    int vis[5*10005];
    int minReorder(int n, vector<vector<int>>& connections) {
        memset(vis,0,sizeof vis);
        vector<vector<int>>adj(n);
        map<int,map<int,int>>mp;
        for(auto&it:connections){
            mp[it[0]][it[1]]=1;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt=0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int cur=q.front();q.pop();
            if(vis[cur])continue;
            vis[cur]=1;
            for(auto&it:adj[cur]){
                if(vis[it])continue;
                if(!mp[it][cur])cnt++,mp[it][cur]=1;
                q.push(it);
            }
        }
        return cnt;
    }
};