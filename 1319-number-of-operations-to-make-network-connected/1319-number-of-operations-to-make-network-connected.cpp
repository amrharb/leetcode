class Solution {
public:
    vector<vector<int>>adj;
    bool vis[100005];
    void dfs(int i){
        vis[i]=1;
        for(auto&it:adj[i]){
            if(!vis[it])dfs(it);
        }
    }
   int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)return -1;
        memset(vis,0,sizeof vis);
       adj=vector<vector<int>>(n);
        int cnt=0;
       for(auto&it:connections){
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
       }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                cnt++;
            }
        }
        return cnt-1;
    }
};