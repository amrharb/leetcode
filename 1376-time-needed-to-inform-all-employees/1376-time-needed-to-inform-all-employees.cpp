class Solution {
public:
    int mx;
    vector<vector<pair<int,int>>>adj;
    void dfs(int i,int cost){
        if(cost>mx)mx=cost;
        for(auto&it:adj[i]){
            dfs(it.first,cost+it.second);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        mx=0;
        adj=vector<vector<pair<int,int>>>(n);
        for(int i=0;i<n;i++){
            if(~manager[i])adj[manager[i]].push_back({i,informTime[manager[i]]});
        }
        dfs(headID,0);
        return mx;
    }
};